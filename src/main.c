#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "ui.h"
#include "scene.h"

int main(int argc, char** argv){
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	SDL_Window* win = SDL_CreateWindow("Vassals of Bloom", 100, 100, WIN_W, WIN_H, 0);
	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	SDL_ShowCursor(0);

	img icon = new_img(rend, "img/icon.png");
	SDL_SetWindowIcon(win, icon.surf);

	main_menu(rend);

	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
