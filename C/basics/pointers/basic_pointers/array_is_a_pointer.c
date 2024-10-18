#include <stdio.h>

int main(){
    int array[5] = {1,2,3,4,5};
    int *p = array;
    p[4] = 45; // pointer acting as an array
    printf("p = %p\n", p);
    printf("p+2 = %p\n", p+2); //prints out the original address like above +8 cuz the compiler is doing 2*(sizeof(int)) = 2*(4)
    printf("array[0] = %i\n", *p);
    printf("array[1] = %i\n", *(p+1));
    printf("array[2] = %i\n", *(p+2));
    printf("array[3] = %i\n", *(p+3));
    printf("array[4] = %i\n", *(p+4));

    //however where arrays and pointer differ is that the array has been allocated its size by the compiler and therefore when you try and
    //access out of the arrays bonds it will throw an error, if you try to do this using a pointer it has no way to check this and you will
    //SEGFAULT :)
}
