# Setup Kafe as scripting language for a project

*page under construction*

You will need `kafe[-d].lib` and `antlr4-runtime.lib` (and possibly the DLL as well) to link to your project.

Then you just have to `#include <kafe/kafe.hpp>` after having added `[KAFE INSTALL DIR]/include/` to the include directories of your compiler.