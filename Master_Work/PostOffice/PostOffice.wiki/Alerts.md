## Overview

In this page you can find information about configured alerts and how to set them up.
For this project we created three condition which will be validated:
* Health checks status - in case services get out of work
* Amount of 5xx errors - to check constant service failure
* Connections amount - since an enormous amount of websocket connections creates a stress condition on the server

Alerts are configured to trigger when condition reaches certain threshold.

Developers will be notified via email and notifications in Teams.

## Create alerts in Azure

* Visit Azure portal and create new resource which will be Alerts

<p align="center">
    <img alt="Create alerts" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/alerts/create-alert.png" />
</p>

* Create a new alert rule

<p align="center">
    <img alt="Create alert rule" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/alerts/add-new-rule.png" />
</p>

* Select your subscription, resource group and resource you want to monitor itself
* Select the condition based on which the alert is to be triggered. You can see a list of configured alerts for current project

<p align="center">
    <img alt="Alert condition" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/alerts/condition.png" />
</p>

* You can change not only condition, but also a way it will be fared. The threshold could be based on average responses, maximum or minimum whatever

<p align="center">
    <img alt="Configure alert" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/alerts/configure-allert.png" />
</p>

* The last step would be to create an Action Group (or use a previously created action group). Besides of name you should also specify notification type. There are a lot of kinds, but we used **emails** and **Teams**. You can find how to configure alerts on Microsoft Teams down below.

<p align="center">
    <img alt="Configure alert" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/alerts/notification.png" />
</p>

## Integrate with Microsoft Teams

Azure alerts in Microsoft Teams could be configured with **Connectors**. You should create a new channel or use the existing one.

* Go to connectors list and find **Incoming Webhook**

<p align="center">
    <img alt="Incomin webhook" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/alerts/incomin-webhook.png" />
</p>

* When you specified a name for a connector you will receive a **Webhook url** which will be used in Azure Webhook alert action.

<p align="center">
    <img alt="Integration With Teams" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/alerts/integration-with-teams.png" />
</p>
