// pointers ludo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <windows.h>
#include "Board.h"
#include "Ludo.h"
#include "Utility.h"
#include "SFML/Graphics.hpp"
using namespace std;

int main()
{
    Ludo L;
    L.Play();
    return 0;
}
