#include <stdio.h>
#include <assert.h>
#include <SDL2/SDL.h>

// define some constants
#define WIDTH 600
#define HEIGHT 400
#define TRUE 1
#define FALSE 0

void draw_pixel(SDL_Renderer *renderer, int x, int y) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_Rect rect = {x, y, 10, 10};
	printf("creating rect at x: %i, y: %i", x, y);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}

int main(void) {

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Point mouse_position; 

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "sdl failed: %s\n", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow("Piksel", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
	if (window == NULL) {
		fprintf(stderr, "sdl failed to create window: %s\n", SDL_GetError());
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		fprintf(stderr, "sdl failed to create renderer: %s\n", SDL_GetError());
		return 1;
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

  /* SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	for (int x = 65; x<WIDTH-60; x=x+60) {
		for (int y = 55; y<HEIGHT-50; y=y+60) {
			SDL_Rect rect = {x, y, 50, 50};
			SDL_RenderFillRect(renderer, &rect);
		}
	} */

	SDL_RenderPresent(renderer);

	int is_running = TRUE;
	SDL_Event event;
	while (is_running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				is_running = FALSE;
			} else if (event.type == SDL_MOUSEBUTTONDOWN) {
				SDL_GetMouseState(&mouse_position.x, &mouse_position.y);
				draw_pixel(renderer, mouse_position.x, mouse_position.y);
			}
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
