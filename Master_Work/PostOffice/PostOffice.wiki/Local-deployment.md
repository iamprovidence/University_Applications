## Overview

Inside ``Infrustructure`` folder you can find ``docker-compose.yml`` that contains all required services for the application to work. You need run ``Infrastructure/runall.cmd`` to start those.

After all services are started run  ``script/runall.cmd``. That script will trigger all application services such as API, UI (Angular) and Background jobs (Sms sender).
