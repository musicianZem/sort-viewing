## sort-viewing

### SDL

based on SDL2

### Run Code

```
mkdir build
cd build
cmake ..
make # if error, check #include <SDL2/SDL.h> for each PC environment
./a.out
```

### Speed Control

on my pc, SDL Render is too fast to draw all.  
so, i add `SDL_Delay(1)` at main loop.

if the project is too slow to show all, change that point.
