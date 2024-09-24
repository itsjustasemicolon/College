#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct node
{
    int n;
    struct node* next;
}node;
node* head=NULL;
void view(node*);
void view(node* ptr)
{
    printf("head->");
    while(ptr!=NULL)
    {
        printf("%i->",ptr->n);
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
                    if(pos==1)
                    {
                        ptr->next=head;
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
                        p->next=ptr;
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
                    node* prev=p;
                    p=p->next;
                    prev->next=p->next;
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
                node* prev;
                node* curr;
                node* nxt;
                prev=head;
                curr=head->next;
                nxt=curr->next;
                prev->next=NULL;
                while(nxt!=NULL)
                {
                    curr->next=NULL;
                    curr->next=prev;
                    prev=curr;
                    curr=nxt;
                    nxt=nxt->next;
                }
                curr->next=prev;
                prev=curr;
                head=prev;

            }
            break;

            case 'f':
            return 0;
        }

    }
    return 0;
}
