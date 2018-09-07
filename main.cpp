#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "bubbleScreen.h"
using namespace std;

const int SCREEN_WIDTH  = 1920/4;
const int SCREEN_HEIGHT = 1080/4;

int main() {
    BubbleScreen *bubble = new BubbleScreen();
    bubble->init(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    bubble->makeData();

    SDL_Event event;
    bool quit = false;
    int i = 0, j = 1, maxp = SCREEN_WIDTH;
    while( !quit ) {
        while( SDL_PollEvent( &event ) ) {
            if( event.type == SDL_QUIT ) {
                quit = true;
            }
        }

        bubble->update();
        bubble->render();
    }
}
