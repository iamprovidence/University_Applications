## Overview

To add notification about changes in repository to Microsoft Teams you need to use **Connectors** for channel.

* Create a new channel or use existing one.
* Right click channel and select **Connectors**
* Find **Github Enterprise**

<p align="center">
    <img alt="Github connector" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/github-notifications/connector.png" />
</p>

* When you finish configuring the name for your connector you will receive **Webhook url**. Copy it. It will be used later

<p align="center">
    <img alt="Webhook url" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/github-notifications/webhook-url.png" />
</p>

* Go to your GitHub repository settings where you will find WebHook configuration. Add recently copied url and specify which event you want to listen

<p align="center">
    <img alt="Configure Webhooks" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/github-notifications/configure-webhooks.png" />
</p>

* At the end you will see notification from Githum in Teams channel

<p align="center">
    <img alt="Notifications" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/github-notifications/notifications.png" />
</p>


