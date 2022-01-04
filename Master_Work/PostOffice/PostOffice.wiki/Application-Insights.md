Follow the steps below to configure App Insights as a logging service. It is included the instructions for setting up App Insights in case you decide to register PostOffice logs locally, or for instance in a production environment.

## Create an App Insights service

* Go to the Azure portal 
* Create new resource
* Select application insights

<p align="center">
    <img alt="Create application insights" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/application-insights-resource.png" />
</p>

* Fulfill required fields

<p align="center">
    <img alt="Application insights" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/create-application-insights.png" />
</p>

* Complete result should look like this

<p align="center">
    <img alt="Created application insights" src="https://github.com/iamprovidence/PostOffice/blob/develop/docs/images/created-application-insights.png" />
</p>

* Retrieve the **Instrumentation Key** generated to be used later on. Go to properties in the portal and copy the key.

## Setting up Application Insights locally

* Go to the root of the project and open the **.env** file where all the environment variables are set.
* Add new variable **ApplicationInsights__InstrumentationKey** and set the Instrumentation Key from your App Insights service that has previously been created

```
...
ApplicationInsights__InstrumentationKey=8323fb13-32aa-46af-b467-8355cf4f8f98
...
```

## Add Application Insights to app

#### Add Application Insights to an ASP.NET Core app

* Install the following nuget package:
  * Microsoft.ApplicationInsights.AspNetCore

* Register AppInsights service by including the **AddApplicationInsightsTelemetry** extension method in your ```ConfigureServices``` ```Startup``` method located at ```Startup.cs```.

```csharp
public class Startup : IStartup
{
	public IServiceProvider ConfigureServices(IServiceCollection services)
	{
			. . .
		services.AddApplicationInsightsTelemetry();
			. . .

		return services.BuildServiceProvider(validateScopes: true);
	}

	public void Configure(IApplicationBuilder app)
	{
			. . .
	}
}
```

#### Add Application Insights to an Angular app

* Install the following npm package:
  * @microsoft/applicationinsights-web

* Import **ApplicationInsights** from ``@microsoft/applicationinsights-web`` to log event.

```javascript
import { ApplicationInsights } from '@microsoft/applicationinsights-web';
...

const appInsights = new ApplicationInsights({
	config: {
		instrumentationKey: "d6f39865-52cc-4a99-8e97-bde3208d0ebf",
		enableAutoRouteTracking: true, // option to log all route changes
	},
});

appInsights.trackEvent({ name: name }, properties);
appInsights.trackMetric({ name: name, average: average }, properties);
appInsights.trackException({ exception: exception, severityLevel: severityLevel });
appInsights.trackTrace({ message: message }, properties);
```

