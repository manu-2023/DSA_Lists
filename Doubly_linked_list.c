#include <stdio.h>
#include <stdlib.h>

typedef struct dnode{
    int info;
    struct dnode *left,*right;
}DNODE;

DNODE *last;

void display(DNODE *list);
DNODE* frontinsertion(DNODE* list,int info);
DNODE* endinsertion(DNODE *list,int info);
DNODE* frontdelition(DNODE* list);
DNODE* enddel(DNODE *list);
DNODE* aftins(DNODE *list,int info,int pinfo);
DNODE* infodel(DNODE* list,int pinfo);


int main()
{
    DNODE *list;
    int x,ch,pinfo;
    list=NULL;
    while (1)
    {
        printf("\n Enter you choice \n 1 -> Front Insertion \n 2 -> Display \n 3 -> End insertion \n 4 -> Front Deletion \n 5 -> End Deletion \n 6 -> After Insertion \n 7 -> Information Deletion \n 8 -> Ordered Inseertion \n 9 -> Exit \n");
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
                printf("Enter the predecessor info : \n");
                scanf("%d", &pinfo);
                list=aftins(list,x,pinfo);
            }break;
      
            case 7:
            {
                printf("Enter the information of the node to delete: \n");
                scanf("%d", &pinfo);
                list=infodel(list,pinfo);

            }break;
            /*
            case 8:
            {
                printf("Enter the information : \n");
                scanf("%d", &x);
                list=ordins(list,x);//insert in order asc or dsc
            }break;

            */

            default : exit(0);
          
        }
    }
    return 0;
}


void display(DNODE *list)
{   
    DNODE *temp;
    if (list == NULL){
        printf("Empty List\n");
    }
    else{
        temp=list;
        while (temp!=NULL){
            printf("-> \t%d ", temp->info);
            temp=temp->right;
        }
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
        last=newnode;

    }
    else
    {
        newnode->right=list;
        list->left=newnode;
        list=newnode; //list is same as head
    }
    return list;
}

DNODE* endinsertion(DNODE *list,int info)
{    
    DNODE *newnode,*temp;
    newnode=(DNODE*) malloc(sizeof(DNODE));
    newnode->info=info;
    newnode->right=NULL;
    newnode->left=NULL;
    if (list==NULL) {
         list=newnode;
         last=list;
    }
    else
    {
        last->right=newnode;
        newnode->left=last;
        last=newnode;
    }
    return list;
}

DNODE* frontdelition(DNODE* list){
    DNODE *temp;
    if (list == NULL){
        printf("Empty List \n");
    }
    else if (list->right == NULL){//if only one node
        temp=list;
        free(temp);
        list=NULL;
    }
    else{
        temp=list;
        list=list->right;
        list->left=NULL;
        free(temp);
    }
    return list;
}

DNODE* enddel(DNODE *list)
{    
    DNODE *newnode,*temp;
    if (list==NULL) {
         printf("Empty List");
    }
    else if(list->right== NULL){//if only one node
        temp=list;
        list=NULL;
        last=NULL;//without this end insertion won't work
        free(temp);
    }
    else
    {  
        temp=last;
        last=last->left;
        last->right=NULL;
        free(temp);
      
    }
    return list;
}

DNODE* aftins(DNODE *list,int info,int pinfo){//inserts when the previous info is in the 
    DNODE *newnode,*temp;
    newnode=(DNODE*) malloc(sizeof(DNODE));
    newnode->info=info;
    newnode->right=NULL;
    newnode->left=NULL;
    if (list==NULL){//ignore first node's predecessor(previous) info
        list=newnode;
    }
    else{
        temp=list;
        while(temp->right!=NULL && temp->info!=pinfo){
            temp=temp->right;
        }
        if (temp->right == NULL && temp->info == pinfo){
            temp->right=newnode;
            newnode->left=temp;

        }
        else if (temp->info == pinfo){
            newnode->right=temp->right;//we should not lose address of further nodes
            newnode->left=temp;
            temp->right=newnode;
            (newnode->right)->left=newnode;
        }
        else{
            printf("Invalid predecessor  node  info");
        }
          
    }
    return list;
}


DNODE* infodel(DNODE* list,int pinfo){
    DNODE *temp=list;
    if (list==NULL){
        printf("Empty list");

    }
    else if(list->right==NULL && temp->info==pinfo){//first node with no further node
        list=NULL;
        last=NULL;
        free(temp);
    }
    else if (temp->info==pinfo){//first node with further nodes
            list=list->right;
            list->left=NULL;
            free(temp);
        }
    else{
        while (temp->right!=NULL && temp->info!=pinfo){//Traversing
            temp=temp->right;
        }
        if (temp->right==NULL && temp->info==pinfo){//Deleteing last node
            temp->left->right=NULL;
            last=temp->left;
            free(temp);
        }
        else if (temp->info==pinfo){//middle deleting
            (temp->left)->right=temp->right;
            (temp->right)->left=temp->left;
            last=temp->left;
            free(temp);
        }
        else{
            printf("Element not found");
        }
    }
    return list;
}