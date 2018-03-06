# Building

## Requirements

### On Windows

You need to download and install CMake 3.5 from https://cmake.org/download/#latest

### On Linux

To install CMake 3.5, open a shell, and type `sudo apt-get install cmake` if cmake wasn't installed before, otherwise `sudo apt-get upgrade`

## Final steps

Open a shell (on Windows, `Win+R` > cmd > `Return`) and go in the folder where you extracted Kafe. Then :

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Depending on your operating system, either a `kafe.exe` or a `kafe` should be generated. You'll need the files in the `folder-where-you-extracted-kafe/dist` to run it (copy them and put them alongside the program).

### In case you generated a Visual Studio solution (Windows only)

Launch the `KafeBuilder.sln` in Visual Studio. Under Project > Properties > Debug, you'll need to set the following things (when the `All configurations` thing is enabled) :

|
------------|-----------------------------------------------------
Environment | `PATH=%PATH%;$(SolutionDir)..\dist\$(Configuration)`
Working dir | `$(SolutionDir)..`

Finally step, right click on the `Kafe` solution to set it as StartUp Project. You're done ! You can build and run using `CTRL`+`F5`

*tip: To use the Hopscotch secured hash map, build with `KAFE_BUILD_WITH_TSL` defined*
