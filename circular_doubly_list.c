#include <stdio.h>
#include <stdlib.h>

typedef struct dnode{
    int info;
    struct dnode *left,*right;
}DNODE;


void display(DNODE *list);
DNODE* frontinsertion(DNODE* list,int info);
DNODE* endinsertion(DNODE *list,int info);
DNODE* frontdelition(DNODE* list);
DNODE* enddel(DNODE *list);

int main()
{
    DNODE *list;
    int x,ch,pinfo;
    list=NULL;
    while (1)
    {
        printf("\n Enter you choice \n 1 -> Front Insertion \n 2 -> Display \n 3 -> End insertion \n 4 -> Front Deletion \n 5 -> End Deletion \n 6) -> Exit \n");
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

            default : exit(0);
          
        }
    }
    return 0;
}


void display(DNODE *list)
{   
    DNODE *temp;
    if (list == NULL){
        printf("\n Empty List\n");
    }
    else{
        temp=list;
        while (temp->right!=list){
            printf("-> \t%d ", temp->info);
            temp=temp->right;
        }
        printf("-> %d ", temp->info);
    }
   
}

DNODE* frontinsertion(DNODE *list,int info)
{   
    DNODE *newnode;
    newnode=(DNODE*) malloc(sizeof(DNODE));
    newnode->info=info;
    newnode->right=NULL;
    newnode->left=NULL;
    if (list==NULL) {
        list=newnode;
        list->right=list;
        list->left=list;
    }
    else
    {
        newnode->right=list;
        newnode->left=list->left;
        list->left=newnode;
        newnode->left->right=newnode;
        list=newnode; //list is same as head
    }
    return list;
}

DNODE* endinsertion(DNODE *list,int info)
{   
    DNODE *newnode;
    newnode=(DNODE*) malloc(sizeof(DNODE));
    newnode->info=info;
    newnode->right=NULL;
    newnode->left=NULL;
    if (list==NULL) {
        list=newnode;
        list->right=list;
        list->left=list;
    }
    else
    {
        newnode->right=list;
        newnode->left=list->left;
        list->left=newnode;
        newnode->left->right=newnode;
    }
    return list;
}


DNODE* frontdelition(DNODE* list){
    DNODE *temp;
    if (list == NULL){
        printf("Empty List \n");
    }
    else if (list->right == list){//if only one node
        temp=list;
        list=NULL;
        free(temp);
        
    }
    else{
        temp=list;
        list->left->right=list->right;\
        list->right->left=list->left;
        list=list->right;
        free(temp);

    }
    return list;
}

DNODE* enddel(DNODE* list){
    DNODE *temp;
    if (list == NULL){
        printf("Empty List \n");
    }
    else if (list->right == list){//if only one node
        temp=list;
        list=NULL;
        free(temp);
        
    }
    else{
        temp=list->left;
        list->left=temp->left;
        list->left->right=list;
        free(temp);


    }
    return list;
}

