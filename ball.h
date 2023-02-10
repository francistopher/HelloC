#ifndef BALL_H_
#define BALL_H_

typedef enum {
	East,
	North,
	West,
	South
} Direction;

typedef struct Coordinate
{
    unsigned short x;
    unsigned short y;
} Coordinate;


void drawBall(SDL_Renderer *renderer, Coordinate* center, Coordinate* position, unsigned short radius, unsigned short radiusI);

void drawPixelWithinRadius(SDL_Renderer *renderer, Coordinate* center, Coordinate* position, unsigned short radius);

void drawBallLayer(SDL_Renderer *renderer, Coordinate* center, Coordinate* position, unsigned short radius, unsigned short radiusI, Direction d, unsigned short subLayerLen, unsigned short layerLen, unsigned short subLayerI, unsigned short layerI);

#endif
