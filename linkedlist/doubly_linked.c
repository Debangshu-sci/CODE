#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head = NULL;
void insertAtFront(int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    if (head == NULL)
    {
        head = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
        return;
    }
    struct node *temp = head;
    temp->prev = new_node;
    new_node->next = temp;
    new_node->prev = NULL;
    head = new_node;
}
void insertAfterValue(int value, int after_value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    struct node *temp;
    temp = head;
    while (temp->data != after_value && temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->next == NULL && temp->data != after_value)
    {
        printf("Value not present\n");
        return;
    }
    new_node->prev = temp;
    new_node->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = new_node;
    temp->next = new_node;
}
void insertAtEnd(int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    if (head == NULL)
    {
        new_node->next = NULL;
        head = new_node;
        new_node->prev = NULL;
        return;
    }
    struct node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = NULL;
}
int deleteAtFront()
{
    struct node *start_node;
    int value;
    start_node = head;
    head = start_node->next;
    start_node->next->prev = NULL;
    value = start_node->data;
    free(start_node);
    return value;
}
int deleteAtEnd()
{
    struct node *end_node;
    int value;
    end_node = head;
    while (end_node->next != NULL)
    {
        end_node = end_node->next;
    }
    end_node->prev->next = NULL;
    value = end_node->data;
    free(end_node);
    return value;
}
int deleteAfterValue(int after_value)
{
    struct node *temp;
    struct node *to_delete_node;
    temp = head;
    int value;
    while (temp->data != after_value)
    {
        temp = temp->next;
    }
    to_delete_node = temp->next;
    temp->next = to_delete_node->next;
    if (temp->next != NULL)
        to_delete_node->next->prev = temp;
    value = to_delete_node->data;
    free(to_delete_node);
    return value;
}
void display()
{
    struct node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}
int main()
{
    int op, val, val2;
  printf
    ("Enter 1: insertion at front\n2: insertion at end\n3: insertion after a value\n4: deletion at front\n5: deletion after a value\n6: deletion at end\n7: display\n");
  printf ("8: exit\n");
  while (1)
    {
        printf("Enter your choice:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter the value\n");
            scanf("%d", &val);
            insertAtFront(val);
            break;
        case 2:
            printf("Enter the value\n");
            scanf("%d", &val);
            insertAtEnd(val);
            break;
        case 3:
            printf("Enter the value to be inserted\n");
            scanf("%d", &val);
            printf("Enter the value after which insertion should take place\n");
            scanf("%d", &val2);
            insertAfterValue(val, val2);
            break;
        case 4:
            val = deleteAtFront();
            printf("Value deleted is : %d\n", val);
            break;
        case 5:
            printf("ENter the value after which deletion should take place\n");
            scanf("%d", &val2);
            val = deleteAfterValue(val2);
            printf("Value deleted is : %d\n", val);
            break;
        case 6:
            val = deleteAtEnd();
            printf("Value deleted is : %d\n", val);
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        }
    }
}


/*

Complexity
Insertion
Worst case time complexity: Θ(n)
Average case time complexity: Θ(1)
Best case time complexity: Θ(1)
Space complexity: Θ(1)
Deletion
Worst case time complexity: Θ(n)
Average case time complexity: Θ(1)
Best case time complexity: Θ(1)
Space complexity: Θ(1)
Display
Worst case time complexity: Θ(n)
Average case time complexity: Θ(n)
Best case time complexity: Θ(n)
Space complexity: Θ(1)
*/