#define WIN_W 900
#define WIN_H 600

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// IMG

typedef struct {
	SDL_Surface* surf;
	SDL_Texture* tex;
} img;

img new_img(SDL_Renderer* rend, char* filename);
void render_img(SDL_Renderer* rend, img i, int x, int y, int w, int h);

// TEXT

typedef struct {
	SDL_Surface* surf;
	SDL_Texture* tex;
	char* msg;
} text;

text new_text(SDL_Renderer* rend, char* msg, int size, SDL_Color clr);
void render_text(SDL_Renderer* rend, text t, int x, int y, int w, int h);

// BUTTON

typedef struct {
	img sprite;
	text txt;
} button;

button new_button(SDL_Renderer* rend, char* imgfile, char* msg, int size, SDL_Color clr);
void render_button(SDL_Renderer* rend, button btn, int x, int y, int w, int h);
