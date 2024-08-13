#include <stdio.h>

/*
// The program generates a "screen" matrix, and places an "object" matrix inside it
// respecting its size. Then, it moves the object and detects the collision with the
// edges of the "screen" matrix, simulating those animations of old DVD players.
*/

int main() {
    // Main Variables

    // Screen size
    int screenHeight = 10;
    int screenWidth = 10;

    // Object size
    int objectHeight = 2;
    int objectWidth = 2;

    // Object position
    int objectPositionX = 2;
    int objectPositionY = 7;

    // Screen Pixel (the pixels on the screen)
    /*
    Ex: = 0

    0 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0

    */
    char screenPixel = '0';

    // Object value (the pixels of the object)
    /*
    Ex: = 1

    0 0 0 0 0
    0 0 1 1 0
    0 0 1 1 0
    0 0 0 0 0
    
    */
    char objectPixel = 'O';

    // Object default move direction (could be the speed too) ex: -5 would be 5 pixels per frame
    int directionX = 1;
    int directionY = 1;

    // Frame rate (frames per second) that will be used on the usleep function in a while loop
    int frameRate = 2;

    // Options
    printf("Do you want to use the default values? (y/n) : ");
    char option;
    scanf("%c", &option);

    // Check if the option is valid
    while (option != 'y' && option != 'n') {
        printf("Please enter a valid option (y/n) : ");
        scanf("%c", &option);
    }

    // Check if the option is 'y' or 'n'
    if (option == 'y') {
        // Default values
        printf("Using default values\n");
        printf("");
    } else {
        // Custom values
        printf("Using custom values\n");
        printf("");
        // Inputs

        // Screen size
        printf("Enter the screen size (height width) Ex '10 10' : ");
        scanf("%d %d", &screenHeight, &screenWidth);

        // Check if the screen values are valid
        while ((screenHeight < 1 && screenWidth < 1)) {
            printf("The screen size is invalid, please enter a valid size: ");
            scanf("%d %d", &screenHeight, &screenWidth);
        }

        // Object size
        printf("Enter the object size (height width) Ex '5 5' : ");
        scanf("%d %d", &objectHeight, &objectWidth);

        // Check if the object is bigger than the screen
        while ((screenHeight < objectHeight || screenWidth < objectWidth) || (objectHeight < 1 && objectWidth < 1)) {
            printf("The object is bigger than the screen or is too small, please enter a valid size: ");
            scanf("%d %d", &objectHeight, &objectWidth);
        }

        // Object position
        printf("Enter the object position (x y) Ex '5 5' : ");
        scanf("%d %d", &objectPositionX, &objectPositionY);

        // Check if the object is out of the screen considering its size
        while ((objectPositionX < 0 || objectPositionY < 0) || (objectPositionX + objectWidth > screenWidth || objectPositionY + objectHeight > screenHeight)) {
            printf("The object is out of the screen, please enter a valid position: ");
            scanf("%d %d", &objectPositionX, &objectPositionY);
        }
    }

    // Create the custom matrix
    int screenMatrix[screenHeight][screenWidth];
    //int objectMatrix[objectHeight][objectWidth];

    while (1) {
        // Clear the screen
        system("cls");
        
        printf("Screen Size: %d %d\n", screenHeight, screenWidth);
        printf("Object Size: %d %d\n", objectHeight, objectWidth);
        printf("Object Position: %d %d\n", objectPositionX, objectPositionY);
        printf("Object Direction: %d %d\n", directionX, directionY);
        printf("Frame Rate: %d\n", frameRate);
        printf("\n");

        // Create the object matrix
        for (int i = 0; i < screenHeight; i++) {
            for (int j = 0; j < screenWidth; j++) {
                // Check if the object is inside the screen
                if (i >= objectPositionY && i < objectPositionY + objectHeight && j >= objectPositionX && j < objectPositionX + objectWidth) {
                    screenMatrix[i][j] = objectPixel;
                } else {
                    screenMatrix[i][j] = screenPixel;
                }
            }
        }

        // Print the screen matrix
        for (int i = 0; i < screenHeight; i++) {
            for (int j = 0; j < screenWidth; j++) {
                if (screenMatrix[i][j] == 0) {
                    printf("%c ", screenMatrix[i][j]);
                } else {
                    printf("%c ", screenMatrix[i][j]);
                }
            }
            printf("\n");
        }

        // Move the object
        objectPositionX += directionX;
        objectPositionY += directionY;

        // Check if the object is colliding with the screen edges
        if (objectPositionX <= 0 || objectPositionX + objectWidth >= screenWidth) {
            directionX *= -1;
        }

        if (objectPositionY <= 0 || objectPositionY + objectHeight >= screenHeight) {
            directionY *= -1;
        }

        // Wait for the next frame
        usleep(1000000/frameRate);
    }
    

    return 0;
}