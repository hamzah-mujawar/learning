#include <ncurses.h>

int main()
{
    int ch;

    initscr(); //start ncurses mode
    raw(); //line buffering disabled
    keypad(stdscr, TRUE); //Allow input of Function keys, and arrow keys
    noecho(); //don't echo() while we getch
    
    printw("Type any character to see it in bold\n");
    ch = getch(); /* if we did't call raw() as we did before we have to press
                   * enter before we enter the program */
    if(ch == KEY_F(1))
        printw("F1 key pressed"); //if we didn't enable keypad we won't get this either
    else{
        printw("The pressed key is ");
        attron(A_BOLD); //used to switch on an attribute to make characters bold
        printw("%c", ch);
        attroff(A_BOLD);//to turn the attribute off
    }
    refresh(); //print it to the screen
    getch(); //wait for user input
    endwin(); //exit out of ncurses mode
    
    return 0;
}
