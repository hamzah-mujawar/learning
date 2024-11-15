// reference: https://github.com/mkirchner/linked-list-good-taste
#include <stdio.h>
#include <stdlib.h>

struct list_item {
    int value;
    struct list_item* next;
};
// define a type from struct and call it list_item
typedef struct list_item list_item;

struct list {
    struct list_item* head;
};
typedef struct list list;

void printlist(list_item* head)
{
    list_item* temp = head;
    while (temp != NULL) {
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

list_item* create_node(int n)
{
    // dynamically allocate memory with the size of 1 list list_item
    // and then point to address of that memory
    list_item* results = malloc(sizeof(list_item));
    if (results == NULL) {
        fprintf(stderr, "Memory allocation failed");
        exit(1);
    }
    results->value = n;
    results->next = NULL;
    return results;
}

/*
 * Two pointers are required, this allows for us to "join" the list when the removal is done, for example:
 * When we find the target node, we enter the condition that checks if curr is not NULL,
 * if prev is not null that means the target node is somewhere in b/w the linked list or at the end,
 * in that case we set prev's next to be equal to curr's next, see below for illustration
 *
 * head->5->6->7->NULL (target = 7)
 *          |  |    |
 *          p  c    c->next
 * head->5->6 (disjointed) -NULL (target deleted)
 *          |               |
 *          p               c->next
 * head->5->6->NULL (joined list)
 *          |
 *          p->next = c->next
 *
 * if prev is null that means that we removed from the start of the list,
 * head->5->6->7->NULL (target = 5) (prev = NULL)
 *       |  |
 *       c  c->next
 * head->(disjointed) 6->7->NULL (target deleted)
 *                    |
 *                    c->next
 * head->6->7->NULL (joined list)
 *  |
 *  l->head = c->next
 *
 *  This function assumes the target exists.
 */
void remove_cs101(list* l, list_item* target)
{
    list_item* curr = l->head, *prev = NULL;
    while (curr != target) {
        prev = curr;
        curr = curr->next;
    }
    if (prev)
        prev->next = curr->next;
    else
        l->head = curr->next;
}

static inline list_item** find_indirect(list* l, list_item* target)
{
    list_item** p = &l->head;
    while (*p != target)
        p = &(*p)->next;
    return p;
}

void remove_elegant(list* l, list_item* target)
{
    list_item** p = find_indirect(l, target);
    *p = target->next;
}
void insert_before(list* l, list_item* before, list_item* item)
{
    list_item** p = find_indirect(l, before);
    *p = item;
    item->next = before;
}
void free_list(list_item* head)
{
    list_item* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main()
{
    list lst = { NULL };
    lst.head = create_node(5);
    lst.head->next = create_node(6);
    lst.head->next->next = create_node(7);

    printlist(lst.head);

    printf("Removed list item: %d\n", lst.head->next->next->value);

    //remove_cs101(&lst, lst.head->next->next);

    remove_elegant(&lst, lst.head->next->next);
    printlist(lst.head);

    list_item* test_1 = malloc(sizeof(list_item));
    test_1->value = 5;
    test_1->next = NULL;
    list_item* test_2 = malloc(sizeof(list_item));
    test_2->value = 30;
    test_2->next = NULL;
    list_item* test_3 = malloc(sizeof(list_item));
    test_3->value = 40;
    test_3->next = NULL;
    printf("Adding %d before %d\n", test_1->value, lst.head->next->value);
    insert_before(&lst, lst.head->next, test_1);
    printlist(lst.head);
    printf("Adding at the end of list\n");
    insert_before(&lst, NULL, test_2);
    printlist(lst.head);
    printf("Adding at the start of list\n");
    insert_before(&lst, lst.head, test_3);
    printlist(lst.head);

    free_list(lst.head);

    return 0;
}
