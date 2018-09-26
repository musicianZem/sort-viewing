#include <SDL.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "bubblesort.h"
#include "radixsort.h"
using namespace std;

const int BUBBL_STARTX = 0;
const int BUBBL_STARTY = 50;
const int RADIX_STARTX = 1000;
const int RADIX_STARTY = 50;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 500;

int main(int argc, char *argv[]) {

	BubbleSort *bubbl = new BubbleSort();
	RadixSort  *radix = new  RadixSort();
	bubbl->init(BUBBL_STARTX, BUBBL_STARTY, SCREEN_WIDTH, SCREEN_HEIGHT);
	radix->init(RADIX_STARTX, RADIX_STARTY, SCREEN_WIDTH, SCREEN_HEIGHT);

	bubbl->makeData();
	radix->makeData();


	SDL_Event event;
	bool quit = false;
	int i = 0, j = 1;
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}

		bubbl->update();
		radix->update();
		bubbl->render();
		radix->render();
		SDL_Delay(1);
	}

	return 0;
}
