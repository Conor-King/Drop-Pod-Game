# Drop-Pod-Game
C++ game for games engineering coursework.

If starting on a new computer or redownloading the repo from scratch and lib/sfml and/or lib/b2d is empty. Open git bash shell in drop-pod-game directory and run command:

git submodule update --init --recursive

This will download the submodules for the project.
To check if that has worked correctly run command:

git submodule status

Results should show:

 e8d2cafa7f1300f5916a2e22f277d998a739e835 lib/b2d (heads/master)
 2f11710abc5aa478503a7ff3f9e654bd2078ebab lib/sfml (2.5.1)


Then compile with CMake. This will show an error for developers just ignore.

CMake Warning (dev) at C:/Program Files/CMake/share/cmake-3.22/Modules/FindPackageHandleStandardArgs.cmake:438 (message):
  The package name passed to `find_package_handle_standard_args` (VORBIS)
  does not match the name of the calling package (Vorbis).  This can lead to
  problems in calling code that expects `find_package` result variables
  (e.g., `_FOUND`) to follow a certain pattern.
Call Stack (most recent call first):
  lib/sfml/cmake/Modules/FindVorbis.cmake:25 (find_package_handle_standard_args)
  lib/sfml/cmake/Macros.cmake:279 (find_package)
  lib/sfml/src/SFML/Audio/CMakeLists.txt:70 (sfml_find_package)
This warning is for project developers.  Use -Wno-dev to suppress it.

IGNORE THIS IT SHOULD STILL COMPILE.