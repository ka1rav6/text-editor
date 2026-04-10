#ifndef DEFINITIONS_H
#define DEFINITIONS_H
// header files
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include "filefunctions.h"
#include "buffer.h"


// namespace usage
using namespace std;


// defined constants
#define ENTER 10
#define BACKSPACE 127
#define ESCAPE 27
#define SPACE 32
#define CLEAR "\033[H\033[2J"



#endif