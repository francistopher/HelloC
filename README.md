# Pong 0.0

- Never knew about this game until high school pretty sad

## Libraries

Install SDL2, it's a good practice to learn how to google

## Compilation
```
clang -v pong.c -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2 -o main.o
```
<br>You should know how to run the object file generated
<br>Don't forget the other c files

## To do

- [ ] dynamically allocate everything

## To do Pong 1.0

- [x] draw ball in terms of radius/diameter instead of rect
- [x] draw ball with roundness
- [x] draw paddles given a length and layers
- [ ] add round edges to paddles
- [ ] add movement to the ball and the paddles
- [ ] have ball bounce off paddles
- [ ] reset ball when it goes out of bounds

- [ ] draw score labels for each paddle
- [ ] create system for determining winner
- [ ] draw intro text
- [ ] draw game over text

## To do Pong 2.0

- [ ] add acceleration property to ball and paddles
- [ ] add friction to ball and paddles
- [ ] provide the option of a donut shaped pong ball

## To do Pong 3.0

- [ ] draw pong ball elliptically 
- [ ] add spin property to ball
- [ ] add impulse property to ball and paddles
- [ ] allow pong ball to compress during contract and expand afterwards  
- [ ] generate custom font pixel by pixel, perhaps line integrals
