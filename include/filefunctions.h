#ifndef FILEFUNCTIONS_H
#define FILEFUNCTIONS_H
#include <string>
#include <vector>
#include "buffer.h"
using namespace std;

//functions
void createFile(string path);
bool fileExists(string path);
void addToFile(string path, string text);
void loadFileToBuffer(string path, Buffer& buffer);
#endif