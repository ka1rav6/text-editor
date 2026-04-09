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
void addToFile(string path, vector<string> text){

}