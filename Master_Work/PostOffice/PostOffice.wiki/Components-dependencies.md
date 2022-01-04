# Overview

Current project use **Onion architecture**. This way allows us to deploy components independently of each other and reduce the amount of changes to rigid modules. Although the business logic layer use infrastructure and user interface layers it does not have direct dependencies on those. That is where we get use of [dependency inversion principle](https://en.wikipedia.org/wiki/Dependency_inversion_principle) and [separated interface pattern](https://martinfowler.com/eaaCatalog/separatedInterface.html).

<p align="center">
    <img alt="Module dependencies" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/module-dependencies.png" />
</p>

Let's dive into each module's structure. All modules are split by vertical slices. First one is **ClientApp**. It contains all required dependencies and describe its domain area.

<p align="center">
    <img alt="ClientApp Component diagram" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/client-app-component-diagram.png" />
</p>

Main module is more complex that is why it uses ideas of **ports and adapters**. The domain code is separated from the technical details and implementation. Application module declare interfaces that is implemented in infrastructure, so it can be independent as well.

<p align="center">
    <img alt="Application component diagram" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/application-component-diagram.png" />
</p>

For **SmsSender** logic is separated from user interface but still deployed as a single unit. This way everything is coupled together and still remains independent of environment.

<p align="center">
    <img alt="SmsSender component diagram" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/sms-sender-component-diagram.png" />
</p>
