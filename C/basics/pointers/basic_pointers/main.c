#include <stdio.h>

int main(){
    int y = 57;
    int *p = &y;

    *p = 54;

    printf("%p, %d, %d\n", p, *p, y);

    int a = 5, b = 0; 
    b = ++a; // when assigning a value and you want it to assign the incremented value use the pre-increment operator
    printf("%d",b);
}
