#include "ball.h"

#ifndef PADDLE_H_
#define PADDLE_H_


typedef struct Dimension
{
    unsigned short layers;
    unsigned short coreLength;
} Dimension;

void drawPaddle(SDL_Renderer *renderer, Coordinate* position, Dimension* size, unsigned short length, unsigned short layer);
void drawVerticalPaddleLayer(SDL_Renderer *renderer, Coordinate* position, Dimension* size, unsigned short layer, unsigned short length);
void drawHorizontalPaddleLayer(SDL_Renderer *renderer, Coordinate* position, Dimension* size, unsigned short layer, unsigned short length);
#endif

