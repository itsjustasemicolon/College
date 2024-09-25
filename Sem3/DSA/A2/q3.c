#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct node
{
    int n;
    struct node* next;
    struct node* prev;
}node;
node* head=NULL;
void view(node*);
void view(node* ptr)
{
    printf("head->%d->",ptr->n);
    ptr=ptr->next;
    while(ptr!=NULL)
    {
        printf("<-%i->",ptr->n);
        ptr=ptr->next;
    }
    printf("NULL");
}
int main()
{
    int noNodes=0;
    while(true)
    {
        printf("\na. Insert a node at a specified position \nb. View List \nc. Delete a node from a specified position. \nd. Count the number of nodes in the linked list. \ne. Reverse the linked list. \nf. Exit \nEnter choice: ");
        char ch;
        scanf(" %c",&ch);
        switch(ch)
        {
            case 'a':
            if(noNodes==0)
            {
                head=(node*)malloc(sizeof(node));
                printf("n: ");
                int no;
                scanf("%i",&no);
                head->n=no;
                head->next=NULL;
                head->prev=NULL;
                noNodes++;
            }
            else
            {
                printf("Enter position: ");
                int pos;
                scanf("%i",&pos);
                if(pos>0 && pos<=noNodes+1)
                {
                    node* ptr=(node*)malloc(sizeof(node));
                    printf("n: ");
                    int no;
                    scanf("%i",&no);
                    ptr->n=no;
                    ptr->next=NULL;
                    ptr->prev=NULL;
                    if(pos==1)
                    {
                        ptr->next=head;
                        head->prev=ptr;
                        head=ptr;
                    }
                    else
                    {
                        int c=1;
                        node* p=head;
                        while(p!=NULL && c<pos-1)
                        {
                            p=p->next;
                            c++;
                        }
                        ptr->next=p->next;
                        if((ptr->next)!=NULL)
                        (ptr->next)->prev=ptr;
                        p->next=ptr;
                        ptr->prev=p;
                    }
                    noNodes++;
                }
                
                else{
                    printf("Invalid position !");
                }

            }
            break;

            case 'b':
            if(noNodes>0)
            view(head);
            else
            printf("Emtpy list ! Invalid request");
            break;

            case 'c':
            if(noNodes>0)
            {
                printf("Enter position: ");
                int pos;
                scanf("%i",&pos);
                if(pos==1)
                {
                    node* p=head;
                    head=p->next;
                    p->next=NULL;
                    head->prev=NULL;
                    free(p);
                    noNodes--;
                }
                else if(pos>1 && pos<=noNodes)
                {
                    int c=1;
                    node* p=head;
                    while(p!=NULL && c<pos-1)
                    {
                        p=p->next;
                        c++;
                    }
                    node* pre=p;
                    p=p->next;
                    pre->next=p->next;
                    if((p->next)!=NULL)
                    (p->next)->prev=pre;
                    p->next=NULL;
                    p->prev=NULL;
                    free(p);
                    noNodes--;
                }
                else
                printf("Invalid position");
            }
            else
            printf("Emtpy list ! Invalid request");
            break;

            case 'd':
            printf("Nodes in linked list: %i",noNodes);
            break;

            case 'e':
            if(noNodes==0)
            printf("Emtpy list ! Invalid request");
            else if(noNodes==1)
            break;
            else
            {
                node* pre;
                node* curr;
                node* nxt;
                pre=head;
                curr=head->next;
                nxt=curr->next;
                pre->next=NULL;
                while(nxt!=NULL)
                {
                    curr->next=pre;
                    curr->prev=NULL;
                    nxt->prev=NULL;
                    pre->prev=curr;
                    pre=curr;
                    curr=nxt;
                    nxt=nxt->next;
                }
                curr->next=pre;
                pre->prev=curr;
                pre=curr;
                head=pre;

            }
            break;

            case 'f':
            return 0;
        }

    }
    return 0;
}
