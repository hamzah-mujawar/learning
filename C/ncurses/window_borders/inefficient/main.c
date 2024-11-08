#include <ncurses.h>

WINDOW* create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW* local_win);

int main()
{
    WINDOW *my_win;
    int startx, starty, width, height;
    int ch;

    initscr();
    cbreak();

    curs_set(0);

    keypad(stdscr, TRUE);

    height = 3;
    width = 10;
    starty = (LINES - height)/2;
    startx = (COLS - width)/2;
    printw("Press F1 to exit");
    refresh();
    my_win = create_newwin(height, width, starty, startx); //creates a window in the middle of the screen

    while((ch = getch()) != KEY_F(1)) //break out of loop when F1 is pressed
    {
        switch(ch)
        {
            case KEY_LEFT:
                destroy_win(my_win);
                my_win = create_newwin(height, width, starty,  --startx);
                break;
            case KEY_RIGHT:
                destroy_win(my_win);
                my_win = create_newwin(height, width, starty, ++startx); 
                break;
            case KEY_UP:
                destroy_win(my_win);
                my_win = create_newwin(height, width, --starty, startx); 
                break;
            case KEY_DOWN:
                destroy_win(my_win);
                my_win = create_newwin(height, width, ++starty, startx); 
                break;
        }
    }
    endwin();
    return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
    WINDOW *local_win;

    local_win = newwin(height, width, starty, startx);
    wborder(local_win, '|', '|', '-', '-', '*', '*', '*', '*'); //draw a box with border
    wrefresh(local_win);

    return local_win;
}

void destroy_win(WINDOW *local_win)
{
    wborder(local_win, ' ', ' ',' ', ' ', ' ', ' ', ' ', ' '); //clears the border on the window
    wrefresh(local_win);
    delwin(local_win); //free memory of that window (does not clear from screen)
}
