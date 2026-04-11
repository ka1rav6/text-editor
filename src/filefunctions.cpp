#include "../include/definitions.h"

bool fileExists(string path){
    if (filesystem::exists(path)) 
        return true;
    return false;
}
void createFile(string path){
    if (fileExists(path)) return;
    ofstream out(path);
    out.close();
}
void addToFile(string path, string text){
    ofstream out(path, ios::trunc);
    out << text;
    out.close();
}
void loadFileToBuffer(string path, Buffer& buffer){
    if (!fileExists(path)) return;
    ifstream in(path);
    vector<char> fileContent((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    for (char c : fileContent) {
        buffer.typeLetter(c);
    }
    in.close();
}