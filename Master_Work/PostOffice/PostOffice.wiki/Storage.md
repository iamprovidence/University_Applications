# Overview

We use in our application **MongoDB** for saving data, so our project has **3 collection of documents**. The **first** document has next structure:

<br>
<p align="center"><img src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/entities-er-diagram.png"/></p>
<br>

One Order can contain **many** Cargoes. Saving Aggregate roots inside NoSql database in one document allows to avoid making a lot of join queries for get all related data as we do in Sql database.

<hr>

Aggregation state is build from domain events. This way we store order snapshot only when it is created and reply events on every fetch.

So the **second** document has next structure:

<br>
<p align="center"><img src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/domain-event-er-diagram.png"/></p>
<br>

As we can see domain events don't have clear structure and therefore it is very good to save them in NoSql database.

<hr>

**Integration events** are used to maintain data consistency. They are logged before sending with **InProgress** state and if the transaction will commit successfully the status will be updated to **Published**.

So the **third** document has next structure:

<br>
<p align="center"><img src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/integration-event-er-diagram.png"/></p>
<br>

