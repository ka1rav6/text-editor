#ifndef FILEFUNCTIONS_H
#define FILEFUNCTIONS_H
#include "definitions.h"

//functions

void createFile(string path);
bool fileExists(string path);
void addToFile(string path, vector<string> text);

#endif