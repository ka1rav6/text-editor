# Textmex (v0.1.1)

A minimal Vim-like terminal text editor written in C++.

## Features
- Gap buffer
- Raw terminal input
- Basic cursor movement
- File saving

## Build
```bash
make 
```

## Run
```bash
./textmex ./newfile.txt #in the same directory
# or:
./textmex ~/Desktop/file.txt
```
## Elemental Difference from vim

Note, though this is still very small scale and at the beginning of its development, it is made to be run on the terminal itself instead of a new app. 


## Future improvements
Ofcourse there are a lot of future improvements right now. The most basic ones probably are:
1. Adding up and down arrow keys and "delete" too.
2. Better UI: More options etc.

## Controls
ESC :q : quit
ESC :wq : save and quit
Arrow keys : move cursor (only left and right done till now)
Backspace : delete

