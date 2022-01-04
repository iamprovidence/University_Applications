﻿using MediatR.Pipeline;

using Microsoft.Extensions.Logging;

using System.Threading;
using System.Threading.Tasks;

namespace Application.Common.Behaviours
{
    public class RequestLogger<TRequest> : IRequestPreProcessor<TRequest>
    {
        private readonly ILogger _logger;

        public RequestLogger(ILogger<TRequest> logger)
        {
            _logger = logger;
        }

        public Task Process(TRequest request, CancellationToken cancellationToken)
        {
            string requestName = typeof(TRequest).Name;

            _logger.LogInformation("LamaAPI Request: {Name} {@Request}", requestName, request);

            return Task.CompletedTask;
        }
    }
}
