#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SCREEN_WIDTH  = 1920/4;
const int SCREEN_HEIGHT = 1080/4;

int handleEvent( SDL_Event &event ) {
    int retValue;
    while( SDL_PollEvent(&event) != 0 ) {
        if( event.type == SDL_QUIT ) {
            retValue = -1;
        }
        switch( event.type ) {
            case SDL_WINDOWEVENT :
                switch( event.window.event ) {
                    case SDL_WINDOWEVENT_CLOSE :
                        retValue = -1;
                        break;
                }
            break;
        }
    }
    return retValue;
}

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("Bubble Sort", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    int screenID = SDL_GetWindowID( window );

    vector<int> arr( SCREEN_WIDTH );

    // origin 
    for(int i=0; i<SCREEN_WIDTH; i++) {
        arr[i] = i%SCREEN_HEIGHT;
    }

    // shuffle
    for(int i=0; i<SCREEN_WIDTH; i++) {
        for(int j=0; j<SCREEN_WIDTH; j++) {
            int ii=rand()%SCREEN_WIDTH;
            int jj;
            do {
                jj = rand()%SCREEN_WIDTH;
            } while( ii == jj );
            swap( arr[ii], arr[jj] );
        }
    }

    SDL_Event event;
    bool quitMsg = false;
    int i = 0, j = 1, maxp = SCREEN_WIDTH;
    while( !quitMsg ) {
        if( handleEvent(event) == -1 ) {
            quitMsg = true;
        }
        if( maxp < 1 ) continue;
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
        if( arr[j-1] > arr[j] ) {
            swap(arr[j-1], arr[j]);
        }
        j++;
        if( j == SCREEN_WIDTH ) {
            j = i+1;
            maxp --;
        }
        for(int t=0; t<SCREEN_WIDTH; t++) {
            SDL_Rect tmp;
            tmp.x = t; tmp.y = SCREEN_HEIGHT - arr[t]; tmp.w = 1; tmp.h = arr[t];
            SDL_RenderFillRect( renderer, &tmp );
        }

        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
        SDL_RenderPresent(renderer);
    }
}
