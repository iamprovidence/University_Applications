# Overview

Here you can find a class diagram of the domain.

The main entity is **Order** as it is a transaction scope union for another entity (**Cargo**). That is why it is marked as **AggregateRoot**.

Order also produce a couple of **domain events**: _OrderCreated_, _OrderStatusChanged_, _OrderCurrentLocationChanged_ and _OrderDeleted_.

There are other building blocks that inherit from **ValueObjectBase**. They don't have an identity and only serve for simplifying developing process by keeping models as close as possible to real world objects.

![Class diagram](https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/class-diagram.png)

Full class diagram can be reviewed [here](https://github.com/iamprovidence/PostOffice/blob/develop/docs/images/class-diagram.png)