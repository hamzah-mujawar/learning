#include <ncurses.h>

int main()
{
    initscr(); // start ncurses mode
    printw("Hello World"); // write hello world to the corresponding buffer for stdscr
    refresh(); // print it on to the actual screen
    getch(); // wait for user input
    endwin(); // end curses mode

    return 0;
}

// Make sure to compile with -lncurses argument 
