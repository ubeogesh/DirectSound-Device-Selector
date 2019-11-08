# DirectSound Device Selector

This DirectSound wrapper allows overriding of application's choice of audio device. 

It is useful for games that don't allow changing audio device (always use default audio device)

Can be used in conjuction with Virtual Audio Cable to capture game sounds separately from other system sounds. 

Usage: 

1) Put dsound.dll in the game's folder
2) Edit the target sound device in windows: add dsound_select anywhere in it's name.

Note: supposedly will only work with 32-bit games, as the original wrappers claim only 32 bit applications support.

### Original License:

### License

Copyright (C) 2019 Elisha Riedlinger

This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
authors be held liable for any damages arising from the use of this software.
Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
applications, and to alter it and redistribute it freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
      original  software. If you use this  software  in a product, an  acknowledgment in the product
      documentation would be appreciated but is not required.
   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
      being the original software.
   3. This notice may not be removed or altered from any source distribution.

Code in this project is taken from:
- [Jari Komppa's dxwrapper](https://github.com/jarikomppa/dxwrapper)
- [d3d8to9](https://github.com/crosire/d3d8to9)
- [Direct3D9 Wrapper DLL](https://gist.github.com/shaunlebron/3854bf4eec5bec297907)
- [DirectSoundControl](https://github.com/nRaecheR/DirectSoundControl)
- [XWA hooks](https://github.com/JeremyAnsel/xwa_hooks/tree/master/DInputLogger)

### Development

Development was done in C++ using Microsoft Visual Studio Community 2017.
