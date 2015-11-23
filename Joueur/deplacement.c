#include <ncurses.h>
#include <unistd.h>
#define DELAY 30000

int main(void) {
  int x = 0, y = 0, y_init=0;
  
  initscr();
  noecho();
  curs_set(FALSE);
  
  while(1) {
    clear();             // Clear the screen of all
                         // previously-printed characters
    mvprintw(y, x, "o"); // Print our "ball" at the current xy position
    refresh();
    usleep(DELAY);       // Shorter delay between movements
    x++;		// Advance the ball to the right
    y++;
    
    if (y==20) y=++y_init;
        if (x==20) { x=0;  }
    		
  }
  
  endwin();
}
