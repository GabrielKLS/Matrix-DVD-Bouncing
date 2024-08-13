#include <stdio.h>

/*
// The program generates a "screen" matrix, and places an "object" matrix inside it
// respecting its size. Then, it moves the object and detects the collision with the
// edges of the "screen" matrix, simulating those animations of old DVD players.
*/

int main() {
    // Main Variables

    // Screen size
    int screenHeigth = 0;
    int screenWidth = 0;

    // Object size
    int objectHeigth = 0;
    int objectWidth = 0;

    // Object position
    int objectPositionX = 0;
    int objectPositionY = 0;

    // Screen Pixel (the pixels on the screen)
    /*
    Ex: = 0

    0 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0

    */
    int screenPixel = 0;

    // Object value (the pixels of the object)
    /*
    Ex: = 1

    0 0 0 0 0
    0 0 1 1 0
    0 0 1 1 0
    0 0 0 0 0
    
    */
    int objectPixel = 1;

    // Object default move direction (could be the speed too) ex: -5 would be 5 pixels per frame
    int directionX = 1;
    int directionY = 1;

    // Frame rate (frames per second) that will be used on the usleep function in a while loop
    int frameRate = 0;

    return 0;
}