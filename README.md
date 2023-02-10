# ci-build-template

---

<p align="center">
  <b>:warning: REPOSITORY UNDER DEVELOPMENT :warning:</b>
</p>

---

Template for build workflows.

The template provides with features described below:

### Caching conda-based and source dependencies

The example workflows make use of the different strategies to manage the cache.

1. Conda-based dependencies are managed via a `.yml` file, whose hashcode is used as part of the cache key.
In this way, whenever some dependency changes, the cache key changes and it is not restored.

2. Source-compiled dependencies are managed via a `.yml` and a `.meta` file that list all of the desired tags/commits and build configurations.
As per the previous point, whenever these file change, the related cache is not restored. In the example case, the related cache is also not restored if the conda-based one is invalidated since the result would be inconsistent.

3. Use of the date as part of the key allows for invalidating the caches based on a fixed period. In the example case, the cache is invalidated every day. If someone wants to save some minutes, they just need to override the step which sets the corresponding variable.

3. Environment variables to explicitly restore and save cache.

### Configurable build system for source-installed dependencies

We use the following tools for the versioning and compiling of the source-installed dependencies:
- [`vcstool`](https://github.com/dirk-thomas/vcstool) lets you specify the list of repositories with the related tag using a `.yml` configuration file.
- [`colcon`](https://colcon.readthedocs.io/en/released) allows you to build sets of packages and to specify build configurations via a dedicated `.meta` file. 

> :warning: These tools are installed via `conda`. If you don't want to use `conda` in your workflows, you will need to install them in some other way.

### Cross-OS configure step

Making use of [ilammy/msvc-dev-cmd action](https://github.com/ilammy/msvc-dev-cmd) we setup some variables that allows for having a single os-independent CMake configuration step using the default compilers of the `ubuntu`, `macos` and `windows` runners.

The used generator is [Ninja](https://ninja-build.org/)


### Show cache and log on error

If the libraries from source build fails, the colcon log is printed out.
If the build step fails, the CMake cache and log and printed out, along with the directory tree.

All the information above are also saved as [artifacts](https://docs.github.com/en/actions/using-workflows/storing-workflow-data-as-artifacts)
