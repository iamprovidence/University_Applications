# Overview

Our project has two **entities**: Order and Cargo. The relationship between them is **one to many** (one Order has many Cargoes).

<br>
<p align="center"><img src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/entities-er-diagram.png"/></p>
<br>

Aggregation state is build from **domain events**. This way we store order snapshot only when it is created and reply events on every fetch.

<br>
<p align="center"><img src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/domain-event-er-diagram.png"/></p>
<br>

**Integration events** are used to maintain data consistency. They are logged before sending with **InProgress** state and if the transaction will commit successfully the status will be updated to **Published**.

<br>
<br>
<p align="center"><img src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/integration-event-er-diagram.png"/></p>
<br>