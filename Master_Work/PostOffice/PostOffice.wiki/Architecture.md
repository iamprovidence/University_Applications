# Overview

This application support division between client and server using **Angular** and **.Net Core** in each side correspondingly. A **single-page application (SPA)** is used to make the website feel more like a native app.

The architecture proposes a **monolith** approach with elaborate **DDD/CQRS** patterns. 

**WebSocket** is the communication protocol between client apps and server. It has been used for synchronous and asynchronous communication as well. 

**MongoDb** is used as a main source of data to store aggregates and domain events. Idempotency and distributed locking is maintained by **Redis**.

Domain events are handled in the server itself, by using MediatR, a simple in-process implementation the Mediator pattern. Cross-cutting concerns (logs, transaction etc) are handled by decorators.

**Message queues** are based on Azure queues, to convey integration events.

**Sms sender** is third party tool that notify clients and is triggered by messages in queue.

![Architecture](https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/architecture.png)