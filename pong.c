/*
 *	File Name: main.c
 *  Date Created: Friday, June 17, 2022
 *  Date Last Updated: Saturday, July 2, 2022
 *  Author: Christopher Francisco
 */

#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#include "ball.h"
#include "paddle.h"

#define WIDTH 640
#define HEIGHT 640

typedef enum {false, true} bool; 

int main(int argc, const char* argv[])
{
    // initialize sdl or exit upon error 
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "FAILED TO INITIALIZE SDL: %s\n", SDL_GetError());
        exit(1);
    }
    // create window, what houses the pixels
    SDL_Window *window = SDL_CreateWindow("Pong 0.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    // create renderer, draws the pixels
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // set background color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    // uses set color to clear
    SDL_RenderClear(renderer);
    // set color to render the ball
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // draw the pong ball
    unsigned short ballRadius = 10;
    Coordinate* center = (Coordinate*)malloc(sizeof(Coordinate));
    center->x = (WIDTH - (ballRadius * 2)) / 2; 
    center->y = (HEIGHT - (ballRadius * 2)) / 2;
    Coordinate* pos = (Coordinate*)malloc(sizeof(Coordinate));
    pos->x = (WIDTH - (ballRadius * 2)) / 2;
    pos->y = (HEIGHT - (ballRadius * 2)) / 2;
    drawBall(renderer, center, pos, ballRadius, 1); // leave the 5th param with a value of 1

    Coordinate* paddlePos = (Coordinate*)malloc(sizeof(Coordinate));
    paddlePos->x = 100;
    paddlePos->y = 100;
    Dimension* paddleSize = (Dimension*)malloc(sizeof(Dimension));
    paddleSize->layers = 10;
    paddleSize->coreLength = 100;

    drawPaddle(renderer, paddlePos, paddleSize, paddleSize->coreLength, 0);


    SDL_RenderPresent(renderer); // have renderer present drawn contents

    bool done = false;
    SDL_StartTextInput();

    while (!done) {
        SDL_Event event;  // create event
        while(SDL_PollEvent(&event)) { // start events loop
            switch(event.type) {
                case SDL_QUIT:
                    done = true;
                    break;
                case SDL_KEYDOWN:
                    printf("KEYDOWNNNNNN\n");
                    break;
                case SDL_KEYUP:
                    printf("KEYUPPPPPPPP\n");
                    break;
                default:
                    break;
            }
        }
    }
    SDL_Quit(); // quit
    free(center);
    free(pos);
    free(paddlePos);
    free(paddleSize);
}
