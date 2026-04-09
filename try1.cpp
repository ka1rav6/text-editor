#include "definitions.h"





int main() {
    termios orig, raw;

    // Get current settings
    tcgetattr(STDIN_FILENO, &orig);
    raw = orig;

    // Disable echo and canonical mode
    raw.c_lflag &= ~(ECHO | ICANON);

    // Apply raw mode
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    vector <string> text;
    // NOTE: Text is actually words stored separately
    cout << "Press keys (press ':q' to quit):\n";
    int cursor_row = 0, cursor_col = 0;
    while (true) {
        char c;
        read(STDIN_FILENO, &c, 1);
        
        if (c == ':'){ 
            // escape sequences
            char c2;
            read(STDIN_FILENO, &c2, 1);
            if (c2 == 'q') break;
            else if (c2 == 's') ; // TODO: save file
            else{
                cout << "Enter a valid combination" << endl;
            }
        } 
        else if (c == ESCAPE) break; // TODO: Add warning if it will save or not
        else if (c == ENTER){
            cursor_row ++;
            cout << cursor_row << endl;
        }
        else{
            cout << "You pressed: " << c << " with ascii value " << (int) c << endl;
            cursor_col ++;
            cout << cursor_col << endl;
        }
    }

    // Restore terminal
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig);

    return 0;
}