#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
}NODE;


NODE* endinsertion(NODE* list,int info);
NODE* frontdelition(NODE* list);
NODE* enddel(NODE* list);
NODE* posins(NODE* list,int x, int pos);
NODE* frontinsertion(NODE* list,int info);
void display(NODE *list);
NODE* posdel(NODE* list, int pos);
NODE* ordins(NODE* list,int info);


int main()
{
    NODE *list;
    int x, ch, pos;
    list=NULL;
    while (1)
    {
        printf("\n Enter you choice \n 1 -> Front Insertion \n 2 -> Display \n 3 -> End insertion \n 4 -> Front Deletion \n 5 -> End Deletion \n 6 -> Position Insertion \n 7 -> Position Deletion \n 8 -> Ordered Inseertion \n 9 -> Exit \n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter the info: \n");
                scanf("%d", &x);
                list=frontinsertion(list,x);
            }break;

            case 2:
            {
                display(list);
             }break;

            case 3:
            {
                printf("Enter the info: \n");
                scanf("%d", &x);
                list=endinsertion(list,x);

            }break;

            case 4:
            {
                list=frontdelition(list);
            }break;

            case 5:
            {
                list=enddel(list);
            }break;

            case 6:
            {
                printf("Enter the info: \n");
                scanf("%d", &x);
                printf("Enter the position: \n");
                scanf("%d", &pos);
                list=posins(list,x,pos);
            }break;

            case 7:
            {
                printf("Enter the position to delete: \n");
                scanf("%d", &pos);
                list=posdel(list,pos);

            }break;

            case 8:
            {
                printf("Enter the information : \n");
                scanf("%d", &x);
                list=ordins(list,x);//insert in order asc or dsc
            }break;

            default : exit(0);
          
        }
    }
    return 0;
}

void display(NODE *list)
{   
    NODE *temp;
    if (list == NULL){
        printf("Empty List\n");
    }
    else{
        temp=list;
        while (temp!=NULL){
            printf("-> \t%d ", temp->info);
            temp=temp->next;
    }
    }
   
}

NODE* frontinsertion(NODE* list,int info)
{   
    NODE *newnode;
    newnode=(NODE*) malloc(sizeof(NODE));
    newnode->info=info;
    newnode->next=NULL;
    if (list==NULL) list=newnode;
    else
    {
        newnode->next=list;
        list=newnode; //list is same as head
    }
    return list;
}

NODE* endinsertion(NODE *list,int info)
{    
    NODE *newnode,*temp;
    newnode=(NODE*) malloc(sizeof(NODE));
    newnode->info=info;
    newnode->next=NULL;
    if (list==NULL) {
         list=newnode;
    }
    else
    {
        temp=list;
        while (temp->next != NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return list;
}

NODE* frontdelition(NODE* list){
    NODE *temp;
    if (list == NULL){
        printf("Empty List \n");
    }
    else{
        temp=list;
        list=list->next;
        free(temp);
    }
    return list;
}

NODE* enddel(NODE* list){
    NODE *temp,*prev;
    if (list==NULL){
        printf("Empty List \n");
    }
    else{
        temp=list;
        if (list->next==NULL)//If we have only one Node
        {
            list=NULL;
            free(temp);//We should not free List 
        }
        else{
            while (temp->next!= NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
        }
        return list;
    }
}

NODE* posins(NODE* list,int x, int pos){
    NODE *newnode,*temp,*prev;
    int i =1;
    newnode=(NODE*) malloc(sizeof(NODE));
    newnode->info=x;
    newnode->next=NULL;
    if (list==NULL){
        list=newnode;//ignore position for first insertion only   
    }
    else{
        temp=list;
        if (pos==1){ //if first node frontinsertion
            newnode->next=list;
            list=newnode;
        }
       
        while(temp->next!=NULL && i<pos){//Checks whether list is exists
                prev=temp;
                temp=temp->next;
                i++;
            }
            if (i==pos){//checks whether we are in the position
                prev->next=newnode;
                newnode->next=temp;
            }
            else if(pos == i+1)//to check it is in ending
            {
                temp->next=newnode;
            }
            else{
                printf("Invalid position");
            }
    }
    return list;
}

NODE* posdel(NODE* list, int pos){
    NODE *newnode,*temp,*prev;
    int i =1;
    if (list==NULL){
        printf("Empty list");//If no list 
    }
    else{
        temp=list;
        if (pos==1){ //if position 1 moves pointer 
            list=list->next;//Moves the pointer
            free(temp);//deletes
        }
        else{
            while(temp->next!=NULL && i<pos){//Checks whether list is exists
                prev=temp;
                temp=temp->next;
                i++;
            }
            if (i==pos){//checks whether we are in the position
                prev->next=temp->next;
                free(temp);
                
            }
            else{
                printf("Invalid position");
            }
        }
    }
    return list;
}

NODE* ordins(NODE* list,int info)
{   
    NODE *newnode,*temp,*prev;
    newnode=(NODE*) malloc(sizeof(NODE));
    newnode->info=info;
    newnode->next=NULL;

    if (list==NULL){
        list=newnode;
    }
    else{
        temp=list;
        if (newnode->info<list->info){
            newnode->next=list;
            list=newnode;
        }
        else{
            while (temp->next!=NULL && temp->info < newnode->info){
                prev=temp;
                temp=temp->next;
            }
            if (temp->info >= newnode->info){
                newnode->next=temp;
                prev->next=newnode;
            }
            else{
                temp->next=newnode;
            }
        }

    return list;
    }
}

