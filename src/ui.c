#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "ui.h"

// IMG

img new_img(SDL_Renderer* rend, char* filename){
	img i;
	i.surf = IMG_Load(filename);
	i.tex = SDL_CreateTextureFromSurface(rend, i.surf);
	return i;
}

void render_img(SDL_Renderer* rend, img i, int x, int y, int w, int h){
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
	SDL_RenderCopy(rend, i.tex, NULL, &dest);
}

// TEXT

text new_text(SDL_Renderer* rend, char* msg, int size, SDL_Color clr){
	text txt;
	TTF_Font* font = TTF_OpenFont("assets/font.ttf", size);
	txt.surf = TTF_RenderText_Solid(font, msg, clr);
	txt.tex = SDL_CreateTextureFromSurface(rend, txt.surf);
	TTF_CloseFont(font);
	txt.msg = msg;
	return txt;
}

void render_text(SDL_Renderer* rend, text t, int x, int y, int w, int h){
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
	SDL_RenderCopy(rend, t.tex, NULL, &dest);
}

// BUTTON

button new_button(SDL_Renderer* rend, char* imgfile, char* msg, int size, SDL_Color clr){
	button btn;
	btn.sprite = new_img(rend, imgfile);
	btn.txt = new_text(rend, msg, size, clr);
	return btn;
}

void render_button(SDL_Renderer* rend, button btn, int x, int y, int w, int h){
	render_img(rend, btn.sprite, x, y, w, h);
	int text_h = h - 20;
	int text_w = (text_h / 2) * strlen(btn.txt.msg);
	render_text(rend, btn.txt, (x + w / 2) - (text_w / 2), (y + h / 2) - (text_h / 2), text_w, text_h);
}
