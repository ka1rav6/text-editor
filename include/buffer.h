#ifndef BUFFER_H
#define BUFFER_H

#include <vector>
#include <string>

class Buffer {
private:
    size_t gap_left; // using gap buffer technique for optimized insertions and deletions
    size_t gap_right;
    std::vector<char> text; //storing text as a vector of characters instead of string for efficient insertions and deletions
    void expandGap();          // resize buffer when gap is full

public:
    // Constructor
    Buffer(size_t initial_size = 1000000);

    // Editing operations
    void typeLetter(char c);
    void backspace();
    void deleteChar();

    // Cursor movement
    void cursorLeft();
    void cursorRight();
    std::pair<int, int> getCursorPosition() const;

    //supporter functions
    void swap(int i, int j);

    // Output
    std::string getText() const;
    
};
#endif // BUFFER_H