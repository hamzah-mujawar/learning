#include <ncurses.h>
#include <string.h>

int main()
{
    char msg[] = "Enter a string: ";
    char str[80];
    int row, col;

    initscr();
    getmaxyx(stdscr, row, col); //get max screen size and store rows and columns in row and col
    mvprintw(row/2, (col-strlen(msg))/2, "%s", msg); //print message at center of screen
    getstr(str); //get string input from user
    mvprintw(LINES-2, 0, "You Entered: %s", str); //ncurses gets LINES and COLS when you can initscr()
    getch();
    endwin();
    //don't need any refresh() here as we aren't using printw() or addch()
    return 0;
}
