#include "../include/definitions.h"

#define INITIAL_BUFFER_SIZE 100000

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
    Buffer buf = Buffer(INITIAL_BUFFER_SIZE);

    cout << "Press keys: Esc +  ':q + enter' to quit):";
    // int cursor_row = 0, cursor_col = 0;
    while (true) {
        cout << "\033[H";          // move cursor to top-left
        cout << "\033[J";          // clear from cursor to end of screen
        cout << buf.getText();
        auto [row, col] = buf.getCursorPosition();
        cout << "\033[" << row << ";" << col - 1 << "H";
        cout.flush();

        char c;
        read(STDIN_FILENO, &c, 1);

        if (c == ESCAPE) { 
            char next;
            read(STDIN_FILENO, &next, 1);
            if (next == ':') {
                string command;
                char ch;

                while (true) {
                    read(STDIN_FILENO, &ch, 1);
                    if (ch == '\n') break;
                    command.push_back(ch);
                }
                if (command == "q") break;
            }
            else if (next == '[') {
                char dir;
                read(STDIN_FILENO, &dir, 1);
                if (dir == 'C') 
                    buf.cursorRight();
                else if (dir == 'D') 
                    buf.cursorLeft();
            }
        }
        else if (c == BACKSPACE || c == 8) {
            buf.backspace();
        }
        else {
            buf.typeLetter(c);
        }
    }
    
    // Restore terminal
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig);
    
    return 0;
}
