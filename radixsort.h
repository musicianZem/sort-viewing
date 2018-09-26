#pragma once

#include <SDL.h>
#include <vector>
#include <queue>
using namespace std;
class RadixSort {
private:
	int m_width;
	int m_height;
	SDL_Window *m_window = nullptr;
	SDL_Renderer *m_renderer = nullptr;
	vector<int> data;
	queue<int> rq[10];
	int dataSize;
	bool isInsert;
	int movei;
	int checkN;
	int popIdx;
	
	const int JARISU = 3; // 299 is max data.

public:
	RadixSort() {
		movei = 0;
		checkN = 1;
	}
	~RadixSort() {
	}

	void init(int xp, int yp, int w, int h) {
		m_width = w;
		m_height = h;
		m_window = SDL_CreateWindow("Radix Sort", xp, yp, w, h, SDL_WINDOW_RESIZABLE);
		m_renderer = SDL_CreateRenderer(m_window, -1, 0);
		SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
		isInsert = true;
	}

	void makeData() {
		dataSize = m_width;
		data.resize(dataSize);
		for (int i = 0; i<dataSize; i++) { data[i] = i % m_height; }
		for (int i = 0; i<dataSize; i++) {
			for (int j = 0; j<dataSize; j++) {
				int ii = rand() % dataSize;
				int jj;
				do { jj = rand() % dataSize; } while (ii == jj);
				swap(data[ii], data[jj]);
			}
		}
	}

	void update() {
		cout << isInsert << " " << checkN << " " << movei << endl;
		if (isInsert) {
			if (checkN < 1000) {
				if (data[movei] < checkN) {
					rq[0].push(data[movei]);
				}
				else {
					int d = data[movei];
					d %= checkN * 10;
					rq[d/checkN].push(data[movei]);
				}
				if( ++movei == dataSize ) {
					movei = 0;
					isInsert = false;
				}
			}
		}
		else {
			for (int i = 0; i < 10; i++) {
				if (!rq[i].empty()) {
					data[movei] = rq[i].front(); rq[i].pop();
					break;
				}
			}
			if (++movei == dataSize) {
				movei = 0;
				isInsert = true;
				checkN *= 10;
			}
		}
	}

	void render() {
		SDL_RenderClear(m_renderer);
		SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
		for (int i = 0; i < dataSize; i++) {
			SDL_Rect temp;
			temp.x = i; temp.y = m_height - data[i]; temp.w = 1; temp.h = data[i];
			if (abs(i - movei) < 5) {
				SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
				SDL_RenderFillRect(m_renderer, &temp);
				SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
			}
			else
				SDL_RenderFillRect(m_renderer, &temp);
		
		}
		SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
		SDL_RenderPresent(m_renderer);
	}
};
