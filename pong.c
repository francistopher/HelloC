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
    if (SDL_Init(SDL_INIT_VIDEO) != 0) { // initialize sdl or exit upon error
        fprintf(stderr, "FAILED TO INITIALIZE SDL: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Window *window = SDL_CreateWindow("Pong 1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN); // create window

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // create what draws contents
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // set color
    SDL_RenderClear(renderer); // clear contents with set color

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // set color
    unsigned short ballRadius = 10; // draw the pong ball
    struct Coordinate center = {
        .x = (WIDTH - (ballRadius * 2)) / 2, 
        .y = (HEIGHT - (ballRadius * 2)) / 2
    };
    struct Coordinate position = {
        .x = (WIDTH - (ballRadius * 2)) / 2, 
        .y = (HEIGHT - (ballRadius * 2)) / 2
    };
    drawBall(renderer, center, position, ballRadius, 1); // leave the 5th param with a value of 1

    struct PaddleCoordinate paddle1Position = {
        .x = 100,
        .y = 100
    };

    struct Dimension paddle1Size = {
        .layers = 10,
        .coreLength = 100
    };

    drawPaddle(renderer, paddle1Position, paddle1Size, paddle1Size.coreLength, 0);


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
}
