//Binary Tree

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char DATA;
    struct Node *LC;
    struct Node *RC;
};

void Build_Tree(struct Node **root,char item)                 //Function to Build Tree
{
    struct Node *ptr;
    ptr=*root;
    char Litem,Ritem,op;
    
    
    if(item!='\0')
    {
        ptr->DATA=item;
    }
    
    if(ptr)
    {
        printf("\n Does the node containing %c have a left subtree(Y/N): ",(ptr)->DATA);
        scanf(" %c",&op);
        if((op=='y')||(op=='Y'))
        {
            struct Node *lcptr;
            lcptr=(struct Node*)malloc(sizeof(struct Node));
            
            printf("\n Enter the element to be inserted: ");
            scanf(" %c",&Litem);
            (ptr)->LC=lcptr;
            //lcptr->DATA=Litem;
            Build_Tree(&lcptr,Litem);
        }
        else 
        {
            if((op!='n')&&(op!='N'))
                printf("\n Invalid Option! Hence No element Inserted!");
            
            struct Node *lcptr;
            lcptr=NULL;
            (ptr)->LC=NULL;
            Build_Tree(&lcptr,'\0');
        }
        
        printf("\n Does the Node containing %c have a Right Subtree(Y/N): ",(ptr)->DATA);
        scanf(" %c",&op);
        
        if((op=='y')||(op=='Y'))
        {
            struct Node *rcptr;
            rcptr=(struct Node*)malloc(sizeof(struct Node));
            
            printf("\n Enter the element to be inserted: ");
            scanf(" %c",&Ritem);
            
            rcptr->DATA=Ritem;
            (ptr)->RC=rcptr;
            Build_Tree(&rcptr,Ritem);
        }
        else
        {
            if((op!='N')&&(op!='n'))
                printf("\n Invalid Item! Hence no element is inserted!");
            
            struct Node *rcptr;
            rcptr=NULL;
            (ptr)->RC=NULL;
            Build_Tree(&rcptr,'\0');
        }
    }
    else
    {
        return;
    }
            
}

void InOrder(struct Node *ptr)   //InOrder Traversal
{
    if(!ptr)
        return;
    else
    {
        InOrder(ptr->LC);
        printf("\t %c",ptr->DATA);
        InOrder(ptr->RC);
    }
}

void PreOrder(struct Node *ptr)
{
    if(!ptr)
        return;
    else
    {
        printf("\t %c",ptr->DATA);
        PreOrder(ptr->LC);
        PreOrder(ptr->RC);
    }
}

void PostOrder(struct Node *ptr)
{
    if(!ptr)
        return;
    else
    {
        PostOrder(ptr->LC);
        PostOrder(ptr->RC);
        printf("\t %c",ptr->DATA);
    }
}

struct Node *SearchNode(struct Node **root,char key)
{
    struct Node *ptr,*temp;
    ptr=*root;
    
    if(!ptr)
        return NULL;
    
    if(ptr->DATA!=key)
    {
        temp=SearchNode((&ptr->LC),key);
        if(temp)
            return temp;
        return SearchNode(&(ptr->RC),key);
    }
    else
        return ptr;
}
void InsertNode(struct Node **root)
{
    char key,op,Litem,Ritem;
    
    if(!(*root))
    {
        printf("\n The Tree is Empty!");
        return;
    }
    
    struct Node *ptr;
    
    printf("\n Enter the element after which the key should be inserted: ");
    scanf(" %c",&key);
    
    ptr=SearchNode(root,key);
    
    
    if(ptr==NULL)
    {
        printf("\n The Key is Not Found!");
        return;
    }
    
    if((!(ptr->LC))||((!(ptr->RC))))
    {
        printf("\n Do you want to enter the item as the left or right child: (L/R)   ");
        scanf(" %c",&op);
        
        if((op=='L')||(op=='l'))
        {
            if(!(ptr->LC))
            {
                struct Node *lc;
                lc=(struct Node*)malloc(sizeof(struct Node));
                
                printf("\n Enter the element to be entered as left child: ");
                scanf(" %c",&Litem);
                
                lc->DATA=Litem;
                lc->LC=NULL;
                lc->RC=NULL;
                ptr->LC=lc;
            }
            else
            {
                printf("\n Insertion as left child is not possible!");
                return;
            }
        }
        else
        {
            if(!(ptr->RC))
            {
                struct Node *rc;
                rc=(struct Node*)malloc(sizeof(struct Node));
                
                printf("\n Enter the element to be entered as right child: ");
                scanf(" %c",&Ritem);
                
                rc->DATA=Ritem;
                rc->LC=NULL;
                rc->RC=NULL;
                ptr->RC=rc;
            }
            else
            {
                printf("\n Insertion as left child is not possible!");
                return;
            }
        }
    }
    else
    {
        printf("\n This Key Node already has a child!!");
        return;
    }
}

struct Node *SearchParent(struct Node *ptr,struct Node *parent,char item)
{
    struct Node *temp;
    if(!ptr)
        return NULL;
    
    if(ptr->DATA==item)
        return parent;
    else
    {
        temp=SearchParent(ptr->LC,ptr,item);
        if(temp)
            return temp;
        return SearchParent(ptr->RC,ptr,item);
    }
}

void DeleteNode(struct Node **root)
{
    char item; 
    
    struct Node *ptr,*parent,*ptr1,*ptr2;
    ptr=*root;
    
    if(!ptr)
    {
        printf("\n The Binary Tree is Empty! ");
        return;
    }
    
    printf("\n Enter the Node to be Deleted: ");
    scanf(" %c",&item);
    
    if(((*root)->DATA==item)&&((*root)->LC==NULL)&&((*root)->RC==NULL))
    {
        *root=NULL;
        printf("\n Now the tree is Empty! ");
        return;
    }
    if(((*root)->DATA==item)&&(((*root)->LC==NULL)||((*root)->RC==NULL)))
    {
        printf("\n This is not a Leaf node! No Deletion possible!");
        return;
    }
    
    
    parent=SearchParent(*root,NULL,item);
    
    if(parent)
    {
        ptr1=parent->LC;
        ptr2=parent->RC;
        
        if(ptr1!=NULL)
        //if(ptr1->DATA==item)
        {
            if((!(ptr1->LC))&&(!(ptr1->RC)))
            {
                parent->LC=NULL;
                free(ptr1);
            }
            else
                printf("\n The Node is not a Leaf node! No Deletion");
        }
        else
        {
            if((!(ptr2->LC))&&(!(ptr2->RC)))
            {
                parent->RC=NULL;;
                free(ptr2);
            }
            else
                printf("\n The Node is not a Leaf Node! No Deletion!");
        }
    }
    else
        printf("\n Node with %c does not exist!. Deletion Failed",item);
}

void main()
{
    int op;
    char item;
    struct Node *root;
    root=(struct Node*)malloc(sizeof(struct Node));
    
    
    printf("\n Create the Binary Tree:");
    printf("\n Enter the root of the Binary Tree: ");
    scanf(" %c",&item);
        
    root->DATA=item;
    root->LC=NULL;
    root->RC=NULL;
    Build_Tree(&root,item);
    
    while(1)
    {
        printf("\n Enter the operation to be performed on the Binary Tree: ");
        printf("\n1.Insert Node \n2.Inorder Traversal \n3.PreOrder Traversal \n4.PostOrder Traversal \n5.Delete Node \n6.Exit \t");
        scanf("%d",&op);
        
        if(op==6)
        {
            printf("\n Exiting..");
            break;
        }
        
        switch(op)
        {
            case 1:
            {
                InsertNode(&root);
                break;
            }
            
            case 2:
            {
                if(!root)
                    printf("\n The tree is Empty!");
                else
                    InOrder(root);
                break;
            }
            
            case 3:
            {
                if(!root)
                    printf("\n The tree is Empty!");
                else
                    PreOrder(root);
                
                break;
            }
            
            case 4:
            {
                if(!root)
                    printf("\n The tree is Empty!");
                else
                    PostOrder(root);
                break;
            }
            
            case 5:
            {
                DeleteNode(&root);
                break;
            }
            
            default:
            {
                printf("\n Invalid Option");
                break;
            }
        }
    }
}




