## Overview

ASP.NET Core 2.2 HealthChecks package is used in API of PostOffice.

API project expose two endpoints (/health-ui and /health-json) to check the current application and all dependencies.

By default, API will open ```/health-ui``` endpoint. It is used in **development** environment to helps verify all services were successfully started.

<p align="center">
    <img alt="Health Checks UI" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/health-checks-ui.png" />
</p>

On the other hand  ```/health-json`` is used in **production** to verify all services work correctly.
```
{
	"Status": "Healthy",
	"Duration": "00:00:00.0140196",
	"HealthChecks": [
		{
			"ComponentName": "Redis",
			"Status": "Healthy",
			"Description": null
		},
		{
		"ComponentName": "Mongo",
		"Status": "Healthy",
		"Description": null
		}
	]
}
```

## Implementing health checks in ASP.NET Core services

HealthChecks is registered in ```Startup```.

```csharp
public class Startup : IStartup
{
	public IServiceProvider ConfigureServices(IServiceCollection services)
	{
			. . .
		services.AddHealthChecks(_configuration);
			. . .

		return services.BuildServiceProvider(validateScopes: true);
	}

	public void Configure(IApplicationBuilder app)
	{
			. . .
		app.UseHealthChecks(_environment);
			. . .
	}
}
```

HealthChecks configured for infrastructure dependencies like Redis and Mongo.

```csharp
public static class HealthChecksConfiguration
{
	public static void AddHealthChecks(this IServiceCollection services, IConfiguration configuration)
	{
		// add different health checks
		services
			.AddHealthChecks()
			.AddCheck<RedisHealthCheck>(name: "Redis")
			.AddMongoDb(
				mongodbConnectionString: configuration.GetValue<string>("MongoDb:ConnectionString"),
				name: "Mongo",
				failureStatus: HealthStatus.Unhealthy);

		// add healthchecks UI
		services
			.AddHealthChecksUI(opt =>
			{
				opt.SetEvaluationTimeInSeconds(5);
				opt.MaximumHistoryEntriesPerEndpoint(10);
				opt.SetApiMaxActiveRequests(1);

				opt.AddHealthCheckEndpoint("PostOffice health", "/health-ui");
			})
			.AddInMemoryStorage();
	}

	public static void UseHealthChecks(this IApplicationBuilder app, IWebHostEnvironment environment)
	{
		// configure health checks UI endpoint
		app.UseHealthChecks("/health-ui", new HealthCheckOptions
		{
			Predicate = (healthCheckRegistration) => true,
			ResponseWriter = UIResponseWriter.WriteHealthCheckUIResponse,
		});

		// configure health checks json endpoint
		app.UseHealthChecks("/health-json", new HealthCheckOptions
		{
			ResponseWriter = (context, report) =>
			{
				// write response for each dependency
				context.Response.ContentType = "application/json";

				var response = new HealthCheckResponse
				{
					Status = report.Status,
					Duration = report.TotalDuration,
					HealthChecks = report.Entries.Select(e => new HealthCheck
					{
						ComponentName = e.Key,
						Status = e.Value.Status,
						Description = e.Value.Description,
					}),
				};

				var responseJson = JsonConvert.SerializeObject(response, Formatting.Indented);

				return context.Response.WriteAsync(responseJson);
			}
		});

		// use health check endpoint
		app.UseHealthChecksUI(options =>
		{
			options.UIPath = "/health";
			options.ApiPath = "/health-ui-api";
			options.UseRelativeApiPath = false;
			options.UseRelativeResourcesPath = false;
		});
	}
}
```

Even though for Mongo default HealthCheck is used, for Redis we implement our own which just check connection to server.

```csharp
internal class RedisHealthCheck : IHealthCheck
{
	private readonly IConnectionMultiplexer _connectionMultiplexer;

	public RedisHealthCheck(IConnectionMultiplexer connectionMultiplexer)
	{
		_connectionMultiplexer = connectionMultiplexer;
	}

	public Task<HealthCheckResult> CheckHealthAsync(HealthCheckContext context, CancellationToken token)
	{
		try
		{
			_connectionMultiplexer.GetDatabase();

			return Task.FromResult(HealthCheckResult.Healthy());
		}
		catch (System.Exception ex)
		{
			return Task.FromResult(HealthCheckResult.Unhealthy(ex.Message));
		}
	}
}
```