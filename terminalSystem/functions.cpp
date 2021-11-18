#include "functions.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int Width = 10;
int Height = 10;

int Pixel(int x, int y)
{
    if (y * Width - (Width - x) - 1 < Width * Height + 1 && y * Width - (Width - x) - 1 > 0)
    {
        return y * Width - (Width - x);
    }
    else
    {
        return 0;
    }
}

void DrawDot(char pixArray[], int colorArray[], int color, int x, int y)
{
    pixArray[Pixel(x, y)] = '#';
    colorArray[Pixel(x, y)] = color + 30;
}

void Write(char pixArray[], int colorArray[], int color, string text, int x, int y)
{
    int g = 0;
    for (int l = 0; l < text.size(); l++)
    {
        pixArray[Pixel(x + g, y)] = text[g];
        colorArray[Pixel(x + g, y)] = color + 30;
        g++;
    }
}

void DrawLine(char pixArray[], int colorArray[], int color, int x1, int y1, int x2, int y2)
{
    const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;

    int error = deltaX - deltaY;
    DrawDot(pixArray, colorArray, color , x2, y2);

    while (x1 != x2 || y1 != y2)
    {
        DrawDot(pixArray, colorArray, color , x1, y1);
        int error2 = error * 2;
        if (error2 > -deltaY)
        {
            error -= deltaY;
            x1 += signX;
        }
        if (error2 < deltaX)
        {
            error += deltaX;
            y1 += signY;
        }
    }
}

void DrawSquare(char pixArray[], int colorArray[], int color, int x1, int y1, int x2, int y2)
{
    DrawLine(pixArray, colorArray, color, x1, y1, x2, y1);
    DrawLine(pixArray, colorArray, color, x2, y1, x2, y2);
    DrawLine(pixArray, colorArray, color, x2, y2, x1, y2);
    DrawLine(pixArray, colorArray, color, x1, y2, x1, y1);
}

void DrawFillSquare(char pixArray[], int colorArray[], int color, int x1, int y1, int x2, int y2)
{
    int x = x1;
    int error;
    if (x2 > x1)
    {
        error = 1;
    }
    else
    {
        error = -1;
    }

    for (int i = 0; i <= abs(x2 - x1); i++)
    {
        DrawLine(pixArray, colorArray, color, x, y1, x, y2);
        x += error;
    }
}

void Circle(char pixArray[], int colorArray[], int color, int xc, int yc, int x, int y)
{
    DrawDot(pixArray, colorArray, color, xc + x, yc + y);
    DrawDot(pixArray, colorArray, color, xc - x, yc + y);
    DrawDot(pixArray, colorArray, color, xc + x, yc - y);
    DrawDot(pixArray, colorArray, color, xc - x, yc - y);
    DrawDot(pixArray, colorArray, color, xc + y, yc + x);
    DrawDot(pixArray, colorArray, color, xc - y, yc + x);
    DrawDot(pixArray, colorArray, color, xc + y, yc - x);
    DrawDot(pixArray, colorArray, color, xc - y, yc - x);
}
 
void DrawCircle(char pixArray[], int colorArrary[], int color, int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    Circle(pixArray, colorArrary, color, xc, yc, x, y);
    while (y >= x)
    {

        x++;

        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        Circle(pixArray, colorArrary, color, xc, yc, x, y);
    }
}

void SCREEN(char pixArray[], int colorArray[])
{
    for (int i = 1; i <= Height; i++)
    {
        for (int j = 1; j <= Width; j++)
        {
            cout << "\x1b[" << colorArray[Pixel(j, i)] << "m" << pixArray[Pixel(j, i)] << "\x1b[0m";
            if (pixArray[Pixel(j, i)] == '#')
                cout << "\x1b[" << colorArray[Pixel(j, i)] << "m" << pixArray[Pixel(j, i)] << "\x1b[0m";
            else
                cout << ' ';
        }
        cout << endl;
    }
}

void ClearArray(char pixArray[], int colorArray[])
{
    for(int  i = 0; i <= Width * Height; i++)
        pixArray[i] = ' ';
    for(int  i = 0; i <= Width * Height; i++)
        colorArray[i] = 30;
}

void ClearScreen()
{
    cout << "\033c";
}

void Timer(int sec)
{
    int time1 = (int)time(0);
    int time2 = (int)time(0);
    while (time2 - time1 != sec)
        time2 = (int)time(0);
}
