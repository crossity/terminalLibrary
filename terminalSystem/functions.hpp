#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include <string>

using namespace std;

extern int Width;
extern int Height;

void Write(char pixArray[], int colorArray[], int color, string text, int x, int y);
int Pixel(int x, int y);
void DrawDot(char pixArray[], int colorArray[], int color, int x, int y);
void DrawLine(char pixArray[], int colorArray[], int color, int x1, int y1, int x2, int y2);
void DrawSquare(char pixArray[], int colorArray[], int color, int x1, int y1, int x2, int y2);
void DrawFillSquare(char pixArray[], int colorArray[], int color, int x1, int y1, int x2, int y2);
void DrawCircle(char pixArray[], int colorArrary[], int color, int xc, int yc, int r);
void ClearScreen();
void SCREEN(char pixArray[], int colorArray[]);
void ClearArray(char pixArray[], int colorArray[]);
void Timer(int sec);

#endif /* functions_hpp */
