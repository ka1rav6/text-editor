
#include "../include/buffer.h"
using namespace std;

Buffer::Buffer(size_t initial_size) {
    gap_left = 0;
    gap_right = initial_size;
    text = std::vector<char>(initial_size);
}
void Buffer::deleteChar() {
    if (gap_right < text.size()) {
        gap_right++;
    }
}
void Buffer::swap(int i, int j) {
        char temp = text.at(i);
        text.at(i) = text.at(j);
        text.at(j) = temp;
}
    void Buffer::typeLetter(char c){
        if (gap_left == gap_right)
            expandGap();
        text.at(gap_left++) = c;
    }
    void Buffer::cursorLeft(){
        if (gap_left >0){
            swap(gap_left-1, gap_right);
            gap_left--;
            gap_right++;
        }
    }
    void Buffer::cursorRight(){
        if (gap_right < text.size()){
            swap(gap_left, gap_right-1);
            gap_left++;
            gap_right--;
        }
    }
    void Buffer::expandGap() {
        int newSize = text.size() * 2;
        std::vector<char> newText(newSize);
        int newGapRight = newSize - (text.size() - gap_right);
        for (int i = 0; i < gap_left; i++)
            newText[i] = text[i];
        for (int i = gap_right; i < text.size(); i++)
            newText[newGapRight + (i - gap_right)] = text[i];

        gap_right = newGapRight;
        text = newText;
    }
    void Buffer::backspace() {
        if (gap_left > 0) {
            gap_left--;
        }
    }
    string Buffer::getText() const {
        string result;
        for (int i = 0; i < gap_left; i++)
            result.push_back(text.at(i));
        for (int i = gap_right; i < text.size(); i++)
            result.push_back(text.at(i));
        return result;
    }

