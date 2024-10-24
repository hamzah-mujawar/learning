// reference: https://github.com/mkirchner/linked-list-good-taste
#include <stdio.h>

struct list_item {
    int value;
    struct list_item *next;
};
typedef struct list_item list_item;

struct list {
    struct list_item *head;
};
typedef struct list list;

void printlist(list_item *head){
    list_item *temp = head;
    while(temp != NULL){
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    list_item n1, n2, n3;
    list lst;

    n1.value = 45;
    n2.value = 46;
    n3.value = 47;

    lst.head = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = NULL;

    printlist(lst.head);
}
