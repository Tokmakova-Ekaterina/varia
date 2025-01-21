#pragma once
#include <iostream>

using namespace std;

void Create2D(char*** arr, int rows, int cols);
int convertCharToInt(char c);
void Show2D(char** arr, int rows, int cols);
void Show2D2Boards(char** arr, char** arr1, int rows, int cols, string name);
void Init2D(char** arr, int rows, int cols, int who, string name);
void targ(char** arr, int rows, int cols, int& x, int& y, int show = 0);
void Init2DComp(char** arr, int rows, int cols);
void Clean2D(char** arr, int rows);
void compFoo();
void manFoo();