#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
    int data;
    struct linkedlist *next;
} node;

node *insert_beg(node *head)
{
    node *temp = head;
    head = (node *)malloc(sizeof(node));
    printf("Enter the data you want to enter: ");
    scanf("%d", &head->data);
    head->next = temp;
    return head;
}

node *insert_end(node *head)
{
    node *temp = head;
    if (head == NULL)
    {
        head = insert_beg(head);
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = (node *)malloc(sizeof(node));
        temp = temp->next;
        printf("Enter the data to be inserted at the end: ");
        scanf("%d", &temp->data);
        temp->next = NULL;
    }
    return head;
}

node *insert_after(node *head)
{
    node *temp, *temp1;
    temp = head;
    int val;
    printf("Enter the value after which you want to enter new node: ");
    scanf("%d", &val);
    while (temp != NULL && temp->data != val)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Insertion not possible!\n");
        return head;
    }
    else
    {
        temp1 = (node *)malloc(sizeof(node));
        printf("Enter the value you want to enter: ");
        scanf("%d", &temp1->data);
        temp1->next = temp->next;
        temp->next = temp1;
    }
    return head;
}

node *del_beg(node *head)
{
    node *temp = head;
    if (head == NULL)
    {
        printf("Deletion not possible!!\n");
    }
    else
    {
        head = head->next;
        printf("Deleted item is %d\n", temp->data);
        free(temp);
    }
    return head;
}

node *del_end(node *head)
{
    node *temp, *prev;
    temp = prev = head;
    if (head == NULL)
    {
        printf("Deletion is not possible!!\n");
    }
    else
    {
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("Deleted item is %d\n", temp->data);
        free(temp);
    }
    return head;
}

node *del_any(node *head)
{
    node *temp, *prev;
    temp = prev = head;
    int val;
    printf("Enter the value you want to delete: ");
    scanf("%d", &val);

    if (temp == NULL)
    {
        printf("Deletion not possible!! List is empty.\n");
    }
    else
    {
        while (temp != NULL && temp->data != val)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("Value %d not found. Deletion not possible.\n", val);
        }
        else
        {
            prev->next = temp->next;
            printf("Deleted item is %d\n", temp->data);
            free(temp);
        }
    }
    return head;
}

void display(node *head)
{
    node *temp = head;
    if (head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    node *head = NULL;
    int ch;
    while (1)
    {
        printf("MENU :\n1.INSERT AT BEGINNING\n2.INSERT AT END\n3.INSERT AFTER A VALUE\n4.DELETE AT BEGINING\n5.DELETE AT END\n6.DELETE ANY\n7.DISPLAY\n8.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = insert_beg(head);
            break;
        case 2:
            head = insert_end(head);
            break;
        case 3:
            head = insert_after(head);
            break;
        case 4:
            head = del_beg(head);
            break;
        case 5:
            head = del_end(head);
            break;
        case 6:
            head = del_any(head);
            break;
        case 7:
            display(head);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}