/*
 * Date Created: 7/27/22
 * 
 */


#include <SDL2/SDL.h>
#include "paddle.h"

/*
 * Draws paddle
 */

void drawPaddle(SDL_Renderer *renderer, Coordinate* position, Dimension* size, unsigned short length, unsigned short layer)
{
	if (length != 0) {
		if (size->layers % 2 == 1) {
			if (layer % 2 == 0) {
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			} else {
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			}
		} else {
			if (layer % 2 == 0) {
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			} else {
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			}
		
		}
		SDL_RenderDrawPoint(renderer, position->x, position->y + length-- - 1);
		drawPaddle(renderer, position, size, length, layer);
	} else {
		if (size->layers % 2 == 0) {
			if (layer % 2 == 0) {
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			} else {
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			}
		} else {
			if (layer % 2 == 0) {
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			} else {
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			}
		
		}
		position->y--;
		position->x--;
		if (size->layers > layer) {
			drawHorizontalPaddleLayer(renderer, position, size, 0, ((layer + 1) * 2) + 1);
			drawVerticalPaddleLayer(renderer, position, size, 0, size->coreLength);
			position->y += size->coreLength;
			drawHorizontalPaddleLayer(renderer, position, size, 0, ((layer + 1) * 2) + 1);
			position->x += ((layer + 1) * 2);
			position->y -= size->coreLength;
			drawVerticalPaddleLayer(renderer, position, size, 0, size->coreLength);
			position->x -= ((layer + 1) * 2);
			size->coreLength += 2;
			drawPaddle(renderer, position, size, length, layer + 1);
		} 
	}

}

void drawVerticalPaddleLayer(SDL_Renderer *renderer, Coordinate* position, Dimension* size, unsigned short layer, unsigned short length)
{
	if (length > 0) {
		SDL_RenderDrawPoint(renderer, position->x, position->y + length--);
		drawVerticalPaddleLayer(renderer, position, size, layer, length);
	}
}

void drawHorizontalPaddleLayer(SDL_Renderer *renderer, Coordinate* position, Dimension* size, unsigned short layer, unsigned short length)
{
	if (length > 0) {
		SDL_RenderDrawPoint(renderer, position->x + --length, position->y);
		drawHorizontalPaddleLayer(renderer, position, size, layer, length);
	}
}

