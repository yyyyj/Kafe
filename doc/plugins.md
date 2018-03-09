# Creating plugins for Kafe

You want to create a binding of your favorite library for Kafe ? Then you are at the right place ! Let's go, we have no time to lose, to continue we'll have to kill a dragon and get you a castle.

Err, sorry, we aren't in a RPG >_<'

## Getting started

### Configuring your IDE

If you have built all the CMake projects, great ! If you didn't and are using an official release, don't worry it's fine. But if you have built only the Kafe VM and not the KafeLib project, you'll need to build it because building plugins relies on `.lib` created by this project (KafeLib).

#### Visual Studio

Create a new empty project, open the properties in `All Configurations`, and under Configuration Properties > C/C++ > General, set `Additional Include Directories` to `[INSTALLATION OF KAFE]/include`. Then under Configuration Properties > Linker > General, set `Additional Librayr Directories` to `[INSTALLATION OF KAFE]/lib/$(Configuration)`.

Finally, go back in the configuration `Debug` and under Configuration Properties > Linker > Input, add `kafe-api-d.lib` to the `Additional Dependencies`. In the configuration `Release`, in the same window, add `kafe-api.lib` to `Additional Dependencies`.

Then in `All Configurations` again, under Configuration Properties > C/C++ > Language, set `C++ Language Standard` to `ISO C++17 Standard`.

#### Code::Block

Create a new empty project and open the build options. In the global configuration, go under Search Directories > Compiler and add `[INSTALLATION OF KAFE]/include` to the paths.

In the Debug configuration, go under Search Directories > Linker and add `[INSTALLATION OF KAFE]/lib/Debug` to the paths. Then under Linker settings > Link libraries, add `kafe-api-d`.

In the Release configuration, go under Search Directories > Linker and add `[INSTALLATION OF KAFE]/lib/Release` to the paths. Then under Linker settings > Link libraries, add `kafe-api`.

Finally, go back in the global configuration, and under Compiler settings > Other compiler options add `-std=c++17` (if you are using GNU GCC Compiler, its version must be >= 5, otherwise it won't work).

#### Compiling under Linux

Your g++ version must be >= 5 to work, because the API needs `<variant>` to compile.

```
$ g++ -c plugin.cpp -std=c++17 -I<kafe-install-path>/include
# if you want to compile in debug mode :
$ g++ plugin.o -o plugin_app -L<kafe-install-path>/lib/Debug -lkafe-api-d
# if you want to compile in release mode :
$ g++ plugin.o -o plugin_app -L<kafe-install-path>/lib/Release -lkafe-api-d
```

### The code

There is a default code your plugin must have to be usable by Kafe :

plugin.hpp

```cpp
#ifndef plugin
#define plugin

#include <kafe/api.hpp>

KAFE_EXPORT const char* getName();
KAFE_EXPORT unsigned long getVersion();
KAFE_EXPORT unsigned long requiredKafeAPI();

#endif // plugin
```

plugin.cpp

```cpp
#include "plugin.hpp"

const char* getName()
{
    return "my sweet plugin !";
}

unsigned long getVersion()
{
    return kafe::abc::createVersionNumber(1, 0, 0);
}

unsigned long requiredKafeAPI()
{
    return KAFE_API_VERSION;
}

KAFE_PLUGIN_ENTRY_POINT
```

To work correctly, the plugins **must** define at least those 3 functions : `getName` (returning the name of the plugin), `getVersion` (returning the version of the plugin) and `requiredKafeAPI` which is the most important one, because if your installation of Kafe relies on the API version X.Y.Z and the plugin needs the X.Y.(Z+1), it will fail. The version needed must be **exactly** the same as the one used by your installation of Kafe. This a kind of protection for Kafe to be sure every plugin stay up-to-date.

Those three functions are the only one which need to be prefixed by `KAFE_EXPORT` when declaring them.

*this page isn't finished yet, I need to introduce much more things (for example : how to register functions in the VM from a plugin, this will need another function and some pointer on function)*