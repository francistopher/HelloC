#ifndef PADDLE_H_
#define PADDLE_H_

struct PaddleCoordinate { // core length top left
	unsigned short x;
	unsigned short y;
};

struct Dimension {
    unsigned short layers;
    unsigned short coreLength;
};


void drawPaddle(SDL_Renderer *renderer, struct PaddleCoordinate position, struct Dimension size, unsigned short length, unsigned short layer);
void drawVerticalPaddleLayer(SDL_Renderer *renderer, struct PaddleCoordinate position, struct Dimension size, unsigned short layer, unsigned short length);
void drawHorizontalPaddleLayer(SDL_Renderer *renderer, struct PaddleCoordinate position, struct Dimension size, unsigned short layer, unsigned short length);
#endif

