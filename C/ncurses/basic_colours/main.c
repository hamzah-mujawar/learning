#include <ncurses.h>

int main(int argc, char *argv[])
{
    initscr();
    start_color(); // start colour mode

    init_pair(1, COLOR_CYAN, COLOR_BLACK); //blue text on black background
    printw("This is a string I've typed to make colourful"); //text that we want to put our effect on
    //mvchgat(0, 0, -1, A_BLINK, 1, NULL);
    move(0,0);
    chgat(-1, A_BLINK, 1, NULL); //alternatively we can just use chgat
    /*
     * First two parameters specify which position to start
     * Third parameter is number of chars to update (-1) means till end of line
     * Forth parameter is the normal attribute you wanted to give to the character
     * Fifth is the color index. Which is given by init_pair(), you can use 0 for no colour
     * Sixth is always NULL
     */
    refresh();
    getch();
    endwin();
    return 0;
}
