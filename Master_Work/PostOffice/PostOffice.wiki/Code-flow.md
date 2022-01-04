# Overview

This page covers the interaction between different components in PostOffice. Since the majority of components behave the same way we will only discuss the ones what does not.

## Create order

The flow of **creation order** involves the use of integration events since that affects other system such as SmsSender. To maintain data consistency we store integration event before sending them to message queue and update their status depending on where there were successfully published or not. On the other hand it might seem like messages could be lost when SmsSender goes down. But this will not happen. The key point here that instead of pushing messages from queue to service we use pulling model. So service maintain its own loads.

<p align="center">
    <img alt="Module dependencies" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/create-order-sequence-diagram.png" />
</p>

## Delete order

Let's just go to simpler but still interesting approach. In delete order request we affect fewer services but the communication between those are asynchronous. We achieved this through use of WebSocket protocol. This way session state is not kept for the entire period but is restored on response.

<p align="center">
    <img alt="Module dependencies" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/delete-order-sequence-diagram.png" />
</p>

## Change order location

This use case also get use of asynchronous communication. Another interesting idea it brings is resource blocking. Since order could be updated by different employees and those updates should be independent we use [pessimistic lock](https://martinfowler.com/eaaCatalog/pessimisticOfflineLock.html) here. This way the resource is blocked before any interaction with it and released at the end.

<p align="center">
    <img alt="Module dependencies" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/change-order-location-sequence%20diagram.png" />
</p>