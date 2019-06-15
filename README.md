# Game Coding Complete 3rd edition source code

## Introdution

Source code for Mike McShaffry's [Game Coding Complete 3rd edition](https://www.amazon.com/Game-Coding-Complete-Third-McShaffry/dp/1584506806). Note that this is not for the [newer edition](https://www.amazon.com/Game-Coding-Complete-Fourth-McShaffry/dp/1133776574), which I do not own.

## Setting up

Refer to the [book's provided instructions](https://github.com/yottaawesome/game-coding-complete-3rd-edition/blob/master/readme_devsetup.txt). You'll need the old [`DirectX SDK`](https://www.microsoft.com/en-au/download/details.aspx?id=6812); note that you may encounter this [error](https://support.microsoft.com/en-au/help/2728613/s1023-error-when-you-install-the-directx-sdk-june-2010). You can find additional information on the SDK [here](https://docs.microsoft.com/en-us/windows/desktop/directx-sdk--august-2009-). Note also that some of the [header files have changed](https://stackoverflow.com/questions/2649634/dxerr9-h-no-such-file-or-directory) since the source code uses an older version of the SDK. Libs and header files (for Boost, Bullet, etc) can be found [here](https://code.google.com/archive/p/gamecode3/downloads).

## Issues

Unfortunately, the code is really dated and no longer compiles with modern C++ compilers. In particular, the Boost files are badly outdated. I intend to go through at some point and update the code and dependencies, however, it's not high on my priority list.
