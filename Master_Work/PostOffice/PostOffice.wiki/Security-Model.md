# Threat Modeling Report

The application threat model is [here](https://github.com/iamprovidence/PostOffice/blob/develop/docs/PostOffice%20threat%20model.tm7) and the full report is [here](https://github.com/iamprovidence/PostOffice/blob/develop/docs/PostOffice%20threat%20model%20full%20report.html). The next text is the short one.

Created on 20.12.2020 23:43:57

## Threat Model Summary:

<table>
    <tr>
        <td>Not Started</td>
        <td>0</td>
    </tr>
    <tr>
        <td>Not Applicable</td>
        <td>1</td>
    </tr>
    <tr>
        <td>Needs Investigation</td>
        <td>19</td>
    </tr>
    <tr>
        <td>Mitigation Implemented</td>
        <td>3</td>
    </tr>
    <tr>
        <td>Total</td>
        <td>23</td>
    </tr>
    <tr>
        <td>Total Migrated</td>
        <td>0</td>
    </tr>
</table>

* * *

## Theat Model Diagram:

![Theat Model Diagram](https://github.com/iamprovidence/PostOffice/blob/develop/docs/images/security%20model/threat-model-diagram.png)

### Interaction: AMQP

![AMQP interaction](https://github.com/iamprovidence/PostOffice/blob/develop/docs/images/security%20model/Interaction-AMQP.png)

#### 1. An adversary may block access to the application or API hosted on SMS sender through a denial of service attack  [State: Needs Investigation]  [Priority: High]

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Denial Of Service</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>An adversary may block access to the application or API hosted on SMS sender through a denial of service
            attack</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Technology</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Medium</td>
    </tr>
</table>

### Interaction: HTTPS

![HTTPS interaction](https://github.com/iamprovidence/PostOffice/blob/develop/docs/images/security%20model/Interaction-HTTPS-Angular-Api.png)

#### 2. An adversary may block access to the application or API hosted on PostOffice.Angular through a denial of service attack  [State: Needs Investigation]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Denial Of Service</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>An adversary may block access to the application or API hosted on PostOffice.Angular through a denial of service attack</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Technology</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Medium</td>
    </tr>
</table>

#### 3. An adversary may block access to the application or API hosted on PostOffice.API through a denial of service attack  [State: Needs Investigation]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Denial Of Service</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>An adversary may block access to the application or API hosted on PostOffice.API through a denial of service attack</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Technology</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Medium</td>
    </tr>
</table>

### Interaction: HTTPS

![HTTPS interaction](https://github.com/iamprovidence/PostOffice/blob/develop/docs/images/security%20model/Interaction-HTTPS-Browser-Angular.png)

#### 4. An adversary may block access to the application or API hosted on PostOffice.Angular through a denial of service attack  [State: Needs Investigation]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Denial Of Service</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>An adversary may block access to the application or API hosted on PostOffice.Angular through a denial of service attack</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Technology</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Medium</td>
    </tr>
</table>

#### 5. An adversary may block access to the application or API hosted on PostOffice.Angular through a denial of service attack  [State: Needs Investigation]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Denial Of Service</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>	An adversary may block access to the application or API hosted on PostOffice.Angular through a denial of service attack</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Technology</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Medium</td>
    </tr>
</table>

### Interaction: Request

![Request interaction](https://github.com/iamprovidence/PostOffice/blob/develop/docs/images/security%20model/Interaction-Api-Redis.png)

#### 6. An adversary may gain unauthorized access to Azure Redis Cache account in a subscription  [State: Needs Investigation]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Elevation Of Privilege</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>An adversary may gain unauthorized access to Azure Redis Cache account in a subscription</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Data</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Low</td>
    </tr>
</table>

#### 7. An adversary can gain access to sensitive data by sniffing traffic to Azure Redis Cache  [State: Mitigation Implemented]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Information Disclosure</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>An adversary can gain access to sensitive data by sniffing traffic to Azure Redis Cache</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Technology</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Low</td>
    </tr>
</table>

### Interaction: Response

![Response interaction](https://github.com/iamprovidence/PostOffice/blob/develop/docs/images/security%20model/Interaction-Api-Redis.png)

#### 8. An adversary may block access to the application or API hosted on PostOffice.API through a denial of service attack  [State: Needs Investigation]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Denial Of Service</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>An adversary may block access to the application or API hosted on PostOffice.API through a denial of service attack</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Technology</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Medium</td>
    </tr>
</table>

### Interaction: Result

![Result interaction](https://github.com/iamprovidence/PostOffice/blob/develop/docs/images/security%20model/Interaction-Api-MongoDB.PNG)

#### 9. An adversary may block access to the application or API hosted on PostOffice.API through a denial of service attack  [State: Needs Investigation]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Denial Of Service</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>An adversary may block access to the application or API hosted on PostOffice.API through a denial of service attack</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Technology</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Medium</td>
    </tr>
</table>

### Interaction: Save

![Save interaction](https://github.com/iamprovidence/PostOffice/blob/develop/docs/images/security%20model/Interaction-Api-MongoDB.PNG)

#### 10. A compromised access key may permit an adversary to have more access than intended to an MongoDB instance   [State: Needs Investigation]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Elevation Of Privilege</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>A compromised access key may permit an adversary to have over-privileged access to an MongoDB instance</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Technology</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Medium</td>
    </tr>
</table>

#### 11. An adversary may gain unauthorized access to MongoDB account in a subscription  [State: Needs Investigation]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Elevation Of Privilege</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>An adversary may gain unauthorized access to MongoDB account in a subscription</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Data</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Low</td>
    </tr>
</table>

#### 12. An adversary may directly connect to MongoDB from anywhere  [State: Needs Investigation]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Elevation Of Privilege</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>An adversary may directly connect to MongoDB from anywhere since MongoDB does not have any Firewall restrictions that can be enforced.</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Data</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Medium</td>
    </tr>
</table>

#### 13. An adversary may read unauthorized content stored in MongoDB  [State: Needs Investigation]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Elevation Of Privilege</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>An adversary may gain elevated privileges on the document stored in MongoDB storage</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Data</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Low</td>
    </tr>
</table>

#### 14. An adversary may gain elevated privileges on MongoDB NoSQL Database  [State: Needs Investigation]  [Priority: High]  

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Elevation Of Privilege</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>An adversary may gain elevated privileges on the contents of MongoDB if over-privileged master or read-only keys are used to connect</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Data</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Medium</td>
    </tr>
</table>

#### 15. An adversary can gain unauthorized access to MongoDB due to loose authorization rules  [State: Needs Investigation]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Elevation Of Privilege</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>Database access should be configured with roles and privilege based on least privilege and need to know principle</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Data</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Medium</td>
    </tr>
</table>

#### 16. An adversary can gain unauthorized access to Azure SQL database due to weak account policy  [State: Needs Investigation]  [Priority: High]

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Elevation Of Privilege</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>Due to poorly configured account policies, adversary can launch brute force attacks on MongoDB</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Data</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Medium</td>
    </tr>
</table>

#### 17. An adversary can gain unauthorized access to database due to lack of network access protection  [State: Mitigation Implemented]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Elevation Of Privilege</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>If there is no restriction at network or host firewall level, to access the database then anyone can attempt to connect to the database from an unauthorized location</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Data</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Low</td>
    </tr>
</table>


#### 18. An adversary can gain access to sensitive data by performing SQL injection  [State: Not Applicable]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Information Disclosure</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>SQL injection is an attack in which malicious code is inserted into strings that are later passed to an instance of SQL Server for parsing and execution. The primary form of SQL injection consists of direct insertion of code into user-input variables that are concatenated with SQL commands and executed. A less direct attack injects malicious code into strings that are destined for storage in a table or as metadata. When the stored strings are subsequently concatenated into a dynamic SQL command, the malicious code is executed.</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Process</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Medium</td>
    </tr>
</table>

#### 19. An adversary can abuse poorly managed MongoDB's access keys  [State: Needs Investigation]  [Priority: Medium] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Information Disclosure</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>An adversary can abuse poorly managed MongoDB's access keys and gain unauthorized access to storage</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Process</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Medium</td>
    </tr>
</table>

#### 20. An adversary can gain access to sensitive PII or HBI data in MongoDB  [State: Needs Investigation]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Information Disclosure</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>Additional controls like Transparent Data Encryption, Column Level Encryption, EKM etc. provide additional protection mechanism to high value PII or HBI data.</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Data</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Low</td>
    </tr>
</table>

#### 21. An adversary may gain access to sensitive clear-text data in CosmosDB  [State: Needs Investigation]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Information Disclosure</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>An adversary may gain access to sensitive clear-text data in DocumentDB storage</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Data</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Low</td>
    </tr>
</table>

#### 22. An adversary may replay stolen long-lived Resource tokens of CosmosDB  [State: Needs Investigation]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Spoofing</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>An adversary may get access to Resouce  tokens used to authenticate to DocumentDB. If the lifetime of these tokens is not finite, the adversary may replay the stolen tokens for a long time.</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Technology</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Low</td>
    </tr>
</table>

#### 23. An adversary can gain unauthorized access to MongoDB due to weak CORS configuration  [State: Mitigation Implemented]  [Priority: High] 

<table>
    <tr>
        <td><b>Category</b></td>
        <td>Spoofing</td>
    </tr>
    <tr>
        <td><b>Description</b></td>
        <td>An adversary can gain gain unauthorized access to MongoDB due to weak CORS configuration</td>
    </tr>
    <tr>
        <td><b>Control Category</b></td>
        <td>Technology</td>
    </tr>
    <tr>
        <td><b>Effort</b></td>
        <td>Low</td>
    </tr>
</table>