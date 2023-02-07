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

2. Source-compiled dependencies are managed via a `.txt` file that lists all of the desired tags/commits.
As per the previous point, whenever the file changes, the related cache is not restored. In the example case, the related cache is also not restored if the conda-based one is invalidated since the result would be inconsistent.

3. Use of the date as part of the key allows for invalidating the caches based on a fixed period. In the example case, the cache is invalidated every day. If someone wants to save some minutes, they just need to override the step which sets the corresponding variable.

3. Environment variables to explicitly restore and save cache.

### Cross-OS configure step

Making use of [ilammy/msvc-dev-cmd action](https://github.com/ilammy/msvc-dev-cmd) we setup some variables that allows for having a single os-independent CMake configuration step using the default compilers of the `ubuntu`, `macos` and `windows` runners.

The used generator is [Ninja](https://ninja-build.org/)


### Output cache on error

If the build step fails, the CMake cache and log and printed out.


