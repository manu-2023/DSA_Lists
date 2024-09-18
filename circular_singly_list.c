#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
}NODE;
NODE* frontinsertion(NODE* list,int info);
NODE* endinsertion(NODE *list,int info);
void display(NODE *list);
NODE* frontdeletion(NODE* list);




int main()
{
    NODE *list;
    int x, ch, pos;
    list=NULL;
    while (1)
    {
        printf("\n Enter you choice \n 1 -> Front Insertion \n 2 -> Display \n 3 -> End insertion \n 4 -> Front Deletion \n 5 -> End Deletion \n ");
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

            // case 5:
            // {
            //     list=enddel(list);
            // }break;

            // case 6:
            // {
            //     printf("Enter the info: \n");
            //     scanf("%d", &x);
            //     printf("Enter the position: \n");
            //     scanf("%d", &pos);
            //     list=posins(list,x,pos);
            // }break;

            // case 7:
            // {
            //     printf("Enter the position to delete: \n");
            //     scanf("%d", &pos);
            //     list=posdel(list,pos);

            // }break;

            // case 8:
            // {
            //     printf("Enter the information : \n");
            //     scanf("%d", &x);
            //     list=ordins(list,x);//insert in order asc or dsc
            // }break;

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
        while (temp->next!=list){
            printf("-> \t%d ", temp->info);
            temp=temp->next;
        }
        printf("-> \t%d ", temp->info);

        
    }
   
}

NODE* frontinsertion(NODE* list,int info)
{   
    NODE *newnode;
    newnode=(NODE*) malloc(sizeof(NODE));
    newnode->info=info;
    newnode->next=NULL;
    if (list==NULL) {
        list=newnode;
        list->next=list;
    }
    else
    {
        NODE *temp=list;
        while (temp->next!=list){
            temp=temp->next;
        }
        newnode->next=list;
        temp->next=newnode;
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
         list->next=newnode;
    }
    else
    {
        temp=list;
        while (temp->next != NULL && temp->next!=list){
            temp=temp->next;
        }
        newnode->next=list;
        temp->next=newnode;

    }
    return list;
}


NODE* frontdeletion(NODE* list)
{  
    NODE *temp1,*temp;
    temp=list;
    temp1=list;
    if (list==NULL) { 
        printf("\n Empty  List");
    }
    else if (list->next==list){
        list=NULL;
        free(temp);
    }
    else
    {
        
        while (temp->next!=list){
            temp=temp->next;
        }
        list=list->next;
        temp->next=list;
        free(temp1);
      
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
            while (temp->next!=list){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
        }
        return list;
    }
}