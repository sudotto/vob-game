#include <stdbool.h>
#include <SDL2/SDL.h>

#include "ui.h"
#include "scene.h"

// MAIN MENU SCENE

void main_menu(SDL_Renderer* rend){
	SDL_Event event;
	Uint32 frame_start;
	Uint32 frame_time;
	int mouse_x;
	int mouse_y;
	bool running = true;

	img logo = new_img(rend, "assets/logo.png");
	img cursor = new_img(rend, "assets/cursor.png");
	SDL_Color clr;
	clr.r = 23;
	clr.g = 25;
	clr.b = 31;
	button btn = new_button(rend, "assets/button.png", "Start", 32, clr);
	while(running){
		frame_start = SDL_GetTicks();
		SDL_GetMouseState(&mouse_x, &mouse_y);
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
					running = false;
					break;
			}
		}
		SDL_SetRenderDrawColor(rend, 65, 255, 255, 255);
		SDL_RenderClear(rend);
		render_img(rend, logo, (WIN_W / 2) - (230*2 / 2), 100, 230*2, 40*2);
		render_button(rend, btn, (WIN_W / 2) - (200 / 2), ((WIN_H / 2) - (40 / 2)) + 10, 200, 40);

		render_img(rend, cursor, mouse_x, mouse_y, 40, 40);
		SDL_RenderPresent(rend);
		frame_time = SDL_GetTicks() - frame_start;
		if(frame_time < 1/60){
			SDL_Delay(1/60 - frame_time);
		}
	}
}

// GAME SCENE

void game(SDL_Renderer* rend){
	SDL_Event event;
	Uint32 frame_start;
	Uint32 frame_time;
	int mouse_x;
	int mouse_y;
	bool running = true;



	while(running){
		frame_start = SDL_GetTicks();
		SDL_GetMouseState(&mouse_x, &mouse_y);
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
					running = false;
					break;
			}
		}
		SDL_SetRenderDrawColor(rend, 65, 255, 255, 255);
		SDL_RenderClear(rend);

		SDL_RenderPresent(rend);
		frame_time = SDL_GetTicks() - frame_start;
		if(frame_time < 1/60){
			SDL_Delay(1/60 - frame_time);
		}
	}
	
}
