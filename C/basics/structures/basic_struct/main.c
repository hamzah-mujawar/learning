#include <stdio.h>

struct person{
    char name[50];
    int age;
    int height;
};

int main(){
    struct person me;
    struct person you;

    me.age = 30;
    you.age = 40;

    printf("%i, %i\n",me.age, you.age);
}
