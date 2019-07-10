#pragma once

#include <SDL2/SDL.h>
#include <vector>
using namespace std;
class BubbleSort {
    private :
        int m_width;
        int m_height;
        SDL_Window *m_window = nullptr;
        SDL_Renderer *m_renderer = nullptr;
        vector<int> data;
        int dataSize;
        int printRed;
		int movei, endPoint;

    public :
		BubbleSort() {
			movei = 0;
        }
        ~BubbleSort() {
        }

        void init(int xp, int yp, int w, int h) {
            m_width = w;
            m_height = h;
            m_window = SDL_CreateWindow("Bubble Sort", xp, yp, w, h, SDL_WINDOW_RESIZABLE);
            m_renderer = SDL_CreateRenderer(m_window, -1, 0);
            SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
            printRed = 0;
        }

        void makeData() {
            dataSize = m_width/5;
            data.resize(dataSize);
            for(int i=0; i<dataSize; i++) { data[i] = i%m_height; }
            for(int i=0; i<dataSize; i++) {
                for(int j=0; j<dataSize; j++) {
                    int ii=rand()%dataSize;
                    int jj;
                    do { jj = rand()%dataSize; } while( ii == jj );
                    swap( data[ii], data[jj] );
                }
            }
			endPoint = dataSize;
        }

        void update() {
			if (endPoint > 0) {
				if (data[movei - 1] > data[movei]) {
					swap(data[movei - 1], data[movei]);
				}
				if (++movei >= endPoint) {
					endPoint--;
					movei = 1;
				}
			}
        }

        void render() {
            SDL_RenderClear(m_renderer);
            SDL_SetRenderDrawColor( m_renderer, 255, 255, 255, 255 );
            for(int i=0; i<dataSize; i++) {
                SDL_Rect temp;
                temp.x = i*m_width/dataSize; temp.y = m_height - data[i]; temp.w = m_width/dataSize; temp.h = data[i];
				if (i == endPoint) {
					SDL_SetRenderDrawColor(m_renderer, 0, 255, 0, 255);
					SDL_RenderFillRect(m_renderer, &temp);
					SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
				} else if(abs(i - movei) < 5) {
                    SDL_SetRenderDrawColor( m_renderer, 255, 0, 0, 255 );
                    SDL_RenderFillRect( m_renderer, &temp );
					SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
                } else {
                    SDL_RenderFillRect( m_renderer, &temp );
                }
            }
            SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 0 );
            SDL_RenderPresent( m_renderer );
        }
};
