// reference: https://github.com/mkirchner/linked-list-good-taste
#include <stdio.h>
#include <stdlib.h>

struct list_item {
    int value;
    struct list_item *next;
};
// define a type from struct and call it list_item
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


list_item *create_node(int n){
	// dynamically allocate memory with the size of 1 list list_item
	// and then point to address of that memory
    list_item *results = malloc(sizeof(list_item));
    if(results == NULL){
        fprintf(stderr, "Memory allocation failed");
        exit(1);
    }
    results->value = n;
    results->next = NULL;
    return results;
}

void free_list(list_item *head){
    list_item *tmp;
    while(head != NULL){
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(){
    list lst = {NULL};
    lst.head = create_node(5);
    lst.head->next = create_node(6);
    lst.head->next->next = create_node(7);
    lst.head->next->next->next = NULL;

    printlist(lst.head);
    free_list(lst.head);

    return 0;

}
