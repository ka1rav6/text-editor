#include "../include/definitions.h"



int main(int argc, char* argv[]) { // TODO: User input of filename as argv.
    cout << CLEAR;
    termios orig, raw;

    // Get current settings
    tcgetattr(STDIN_FILENO, &orig);
    raw = orig;
    
    // Disable echo and canonical mode
    raw.c_lflag &= ~(ECHO | ICANON);
    
    // Apply raw mode
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    Buffer buf = Buffer();

    cout << "Press keys: Esc +  ':q + enter' to quit):\n";
    int cursor_row = 0, cursor_col = 0;
    while (true) {
        char c;
        read(STDIN_FILENO, &c, 1);
        
        if (c == ESCAPE){ 
            // escape sequences
            string command;
            getline(cin, command);
            if (command == ":q") break;
            else if (command == ":s") ; // TODO: save file
            else{
                cout << "Enter a valid combination" << endl;
            }
        } 
        else{
            cout << c;
            buf.typeLetter(c);
            cursor_col ++;
            cout << buf.getText();
        }
    }
    
    // Restore terminal
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig);
    
    return 0;
}
