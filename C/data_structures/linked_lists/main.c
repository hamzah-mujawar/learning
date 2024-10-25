// reference: https://github.com/mkirchner/linked-list-good-taste
#include <stdio.h>
#include <stdlib.h>

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

list_item *create_list(int n){
    list_item *results = malloc(sizeof(list_item));
    results->value = n;
    results->next = NULL;
    return results;
}

int main(){
    list lst;
    lst.head = create_list(5);
    lst.head->next = create_list(6);
    lst.head->next->next = create_list(7);
    lst.head->next->next->next = NULL;

    printlist(lst.head);
}
