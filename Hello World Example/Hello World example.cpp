#include <iostream>
#include <string>
#include "functions.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Width = 12;
    Height = 1;
    
    // We should make pixel and color arrays
    char pixArray[Width * Height + 1];
    for(int  i = 0; i <= Width * Height; i++)
        pixArray[i] = ' ';
    int colorArray[Width * Height + 1];
    for(int  i = 0; i <= Width * Height; i++)
        colorArray[i] = 30;
    
    ClearScreen(); // Clearing screen
    
    Write(pixArray, colorArray, Cyan, "Hello World!", 1, 1); // Write "Hello World!" on the screen at coordinat x:1 y:1
    
    SCREEN(pixArray, colorArray); // Its shows screen to user
    return 0;
}
