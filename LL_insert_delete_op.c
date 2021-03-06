#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

void delete_last_node(struct node **head) {
  struct node *prev = NULL, *cur = NULL;

  if(head == NULL || *head == NULL) return;

  if((*head)->next == NULL) {
    free(*head);
    *head = NULL;
  }

  prev = *head;
  cur = prev->next;

  while(cur->next) {
    prev = prev->next;
    cur = cur->next;
  }

  prev->next = NULL;
  free(cur);
}

void delete_after_data(struct node* head_ref, int position)
{

 if (head_ref == NULL)
      return;

   struct node* temp = head_ref;

    if (position == 0)
    {
        head_ref = temp->next;   // Change head 
        free(temp);               // free old head 
        return;
    }

    for (int i=0; temp!=NULL && i<position-2; i++)
         temp = temp->next;

   if (temp == NULL || temp->next == NULL)
         return;

    struct node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

/*Print the linked list*/
void print_list(struct node *head) {

    while(head)
    {
        printf("%d->", head->val);
        head = head->next;
    }

}

void insert_front(struct node **head, int value) {

    struct node * new_node = NULL;

    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf(" Out of memory");
    }

    new_node->val = value;

    new_node->next = *head;

    *head = new_node;
}

void main()
{
    int count = 0, i, val;
    struct node * head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &count);

    for (i = 0; i < count; i++)
    {
        printf("Enter %dth element: ", i);
        scanf("%d", &val);
        insert_front(&head, val);
    }

    delete_last_node(&head);
    delete_after_data(head,3);
    print_list(head);
}