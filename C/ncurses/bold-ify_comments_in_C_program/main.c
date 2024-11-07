#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int ch, prev, row, col;
    prev = EOF;
    FILE* fp;
    int x, y;
    keypad(stdscr, TRUE); //Allow input of Function keys, and arrow keys
    if (argc != 2) {
        printf("Usage: %s <a c file name>\n", argv[0]);
        exit(1);
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Cannot open input file");
        exit(1);
    }
    initscr(); /* Start curses mode  */
    getmaxyx(stdscr, row, col); /* Find boundaries of the screen */
    while ((ch = fgetc(fp)) != EOF) /* read the file till we reach the end */
    {
        getyx(stdscr, y, x); /* get current cursor position */
        if (y == (row - 1)) /* are we are the end of the screen */
        {
            printw("<- Press Any Key ->"); /* tell the user to press a key */
            getch();
            clear(); /* clear the screen */
            move(0, 0); /* start at the beginning of the screen */
        }
        if (prev == '/' && ch == '*') /* If it is / and * together then bold on */ {
            attron(A_BOLD); /* Turns bold on (attribute) */
            getyx(stdscr, y, x); /* get the current cursor position where we found the / and * */
            move(y, x - 1); /* back up one space */
            printw("%c%c", '/', ch); /* print entire comment in bold */
        } else
            printw("%c", ch);
        refresh();
        if (prev == '*' && ch == '/') /* if we get * and then / switch off bold */
            attroff(A_BOLD);

        prev = ch;
    }
    printw("<- END OF FILE. Press Any Key to Exit the Program ->");
    getch();
    endwin(); /* end curses mode */
    fclose(fp);
    return 0;
}
