#ifndef FILEFUNCTIONS_H
#define FILEFUNCTIONS_H
#include <string>
#include <vector>
using namespace std;

//functions
void createFile(string path);
bool fileExists(string path);
void addToFile(string path, vector<string> text);

#endif