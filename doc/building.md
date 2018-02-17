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
