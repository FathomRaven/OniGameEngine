# OniGameEngine

Basic little game engine, based off of the tutorial series from Ather Omar.

Docs in github wiki:
https://github.com/FathomRaven/OniGameEngine/wiki

#### Libraries Used:

* SDL
* SDL_Image
* SDL_TTF
* SDL_Mixer

#### Compiling with GCC:
```
g++ src/*.cpp -I./include/ -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -o ./bin/debug/main.exe
```
Executable must be in debug in order to find assets 
