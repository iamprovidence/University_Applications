This page contains a brief setup description for CI/CD pipelines.

## Build pipelines YAML definitions

In repository root you can find `appveyor.yml` file that contains YAML instruction for build pipelines.

The build will be triggered if a new pull request is created. Any other change won't trigger the build. 

<p align="center">
    <img alt="AppVeyour project" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/appveyor-build.png" />
</p>

Please, refer the [AppVeyor YAML build pipelines documentation](https://www.appveyor.com/docs/build-configuration/) for more information.

## AppVeyor Build pipelines

We have a build pipeline for the entire solution created from the YAML file. To create build pipeline from an existing YAML file, create a new project pipeline in AppVeyor:

<p align="center">
    <img alt="AppVeyour project" src="https://raw.githubusercontent.com/iamprovidence/PostOffice/develop/docs/images/appveyor-project.png" />
</p>
