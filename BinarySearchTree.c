//Binary Search Tree Sort 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int DATA;
    struct Node *LC;
    struct Node *RC;
};

void Sort(struct Node *ptr)
{
    if(!ptr)
        return;
        
    if(ptr!=NULL)
    {
        Sort(ptr->LC);
        printf("%d \t",ptr->DATA);
        Sort(ptr->RC);
    }
}

void Insert(struct Node **root,int item)
{
    struct Node *ptr,*ptr1;
    ptr=*root;
    
    if(!ptr)
    {
        
        *root=(struct Node*)malloc(sizeof(struct Node));
        (*root)->DATA=item;
        (*root)->LC=NULL;
        (*root)->RC=NULL;
    }
    else
    {
        char flag;
        flag='f';
        
        while((ptr)&&(flag=='f'))
        {
            if(item<(ptr->DATA))
            {
                ptr1=ptr;
                ptr=ptr->LC;
            }
            else if(item>=(ptr->DATA))
            {
                ptr1=ptr;
                ptr=ptr->RC;
            }
        }
        if(!ptr)
        {
            struct Node *new;
            new=(struct Node*)malloc(sizeof(struct Node));
            
            new->DATA=item;
            new->LC=NULL;
            new->RC=NULL;
            
            if(ptr1->DATA<item)
                ptr1->RC=new;
            else
                ptr1->LC=new;
        }
    }
}

void main()
{
    int n,item;
    
    struct Node *root;
    root=(struct Node*)malloc(sizeof(struct Node));
    
    root=NULL;
    
    printf("\n Enter the number of elements you would like to sort: ");
    scanf("%d",&n);
    
    printf("\n Enter the elements you would like to sort: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&item);
        Insert(&root,item);
    }
    
    printf("\n The sorted elements are: ");
    Sort(root);

}

