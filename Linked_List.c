//Program to implement Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int DATA;
    struct Node *LINK;
};

void Insert_Beginning(struct Node **header, int item);
void Insert_End(struct Node **header, int item);
void Insert_Any(struct Node **header, int item, int key);
void Delete_Beginning(struct Node **header);
void Delete_End(struct Node **header);
void Delete_Any(struct Node **header, int key);
void Display(struct Node *header);

void main(){
    int op,item,key;
    struct Node *header;

    header = (struct Node*)malloc(sizeof(struct Node));
    
    header->LINK = NULL;


    while(1){
        printf("\n Enter the operation to be carried out on the linked list: ");
        printf("\n1.INSERT AT BEGINNING\n2.INSERT AT END\n3.INSERT ANYWHERE\n4.DELETE BEGINNING\n5.DELETE END\n6.DELETE ANYWHERE\n7.DISPLAY\n8.EXIT"); 
        scanf("%d",&op);

        if(op == 8){
            printf("\n Exiting....");
            exit(0);
        }

        switch(op)
        {
            case 1:
            {
                printf("\n Enter the element to be inputtd into the Linked List: ");
                scanf("%d",&item);

                Insert_Beginning(&header,item);
                break;
            }

            case 2:
            {
                printf("\n Enter the element to be inputtd into the Linked List: ");
                scanf("%d",&item);

                Insert_End(&header,item);
                break;
            }
        
            case 3:
            {
                printf("\n Enter the element to be inputtd into the Linked List: ");
                scanf("%d",&item);

                printf("\n Enter the element after which the item should be inputted: ");
                scanf("%d",&key);

                Insert_Any(&header,item,key);
                break;
            }
            
            case 4:
            {
                Delete_Beginning(&header);

                break;
            }
            
            case 5:
            {
                Delete_End(&header);

                break;
            }
            
            case 6:
            {
                printf("\n Enter the element to be deleted: ");
                scanf("%d",&key);

                Delete_Any(&header,key);

                break;
            }
            
            case 7:
            {
                Display(header);
                break;
            }
            
        

            default:
            {
                printf("\n InValid Option!");
                break;
            }
        }
        
    }
}

void Insert_Beginning(struct Node **header, int item){

    if(*header == NULL){
        printf("\n This Linked List is Empty!");
        return;
    }
    else{
        struct Node *new;
        new = (struct Node*)malloc(sizeof(struct Node));

        new->DATA = item;
        new->LINK = (*header)->LINK;
        (*header)->LINK = new;
    }

}

void Insert_End(struct Node **header, int item){

    if(*header == NULL){
        printf("\n This Linked List is Empty!");
        return;
    }
    else{
        struct Node *new, *ptr;
        new = (struct Node*)malloc(sizeof(struct Node));

        ptr = *header;

        while(ptr->LINK){
            ptr = ptr->LINK;
        }

        new->DATA = item;
        new->LINK = NULL;
        ptr->LINK = new;
    }

}

void Insert_Any(struct Node **header, int item, int key){

    /*if(*header == NULL){
        printf("\n This Linked List is Empty!");
        return;
    }*/
    if((*header)->LINK == NULL){
        printf("\n This Linked List is Empty!\n");
    }
    else{
        struct Node *new, *ptr, *ptr1;
    
        ptr = *header;

        while((!(ptr->LINK))&&(ptr->DATA != key)){
            ptr = ptr->LINK;
        }

        if(ptr->DATA == key){
            new = (struct Node*)malloc(sizeof(struct Node));
            printf("\n In here:");
            new->DATA = item;
            new->LINK = ptr->LINK;
            ptr->LINK = new;
        }
        else if(ptr->LINK == NULL){
            printf("\n The Key is not Found! Cannot Insert element!");
            return;
        }
    }
}
void Delete_Beginning(struct Node **header){

    struct Node *ptr;

    if((*header)->LINK == NULL){
        printf("\n Cannot remove elements as Linked List is Empty");
        return;
    }

    ptr = (*header)->LINK;

    if(ptr->LINK != NULL){
        (*header)->LINK = ptr;
        free(ptr);
    }
}

void Delete_End(struct Node **header){

    struct Node *ptr, *ptr1;

    if((*header)->LINK == NULL){
        printf("\n Cannot remove elements as Linked List is Empty");
        return;
    }

    ptr = (*header);

    if(ptr->LINK){
        ptr1 = ptr;
        ptr = ptr->LINK;
    }

    ptr1->LINK = NULL;
    free(ptr);

}

void Delete_Any(struct Node **header, int key){

    struct Node *ptr, *ptr1;

    if((*header)->LINK == NULL){
        printf("\n Cannot remove elements as Linked List is Empty");
        return;
    }

    ptr = (*header);

    if((!(ptr->LINK)) && (ptr->DATA != key)){
        ptr1 = ptr;
        ptr = ptr->LINK;
    }

    if(ptr->DATA == key)
    {
        ptr1->LINK = ptr->LINK;
        free(ptr);
    }
    else if(ptr->LINK == NULL){
        printf("\n Key Not Found! ");
    }

}

void Display(struct Node *header){
    struct Node *ptr = header->LINK;

    if(ptr == NULL){
        printf("\n The Linked List is Empty!");
        return;
    }

    printf("\n The Linked List is: ");
    while(ptr){
        printf("\n %d",ptr->DATA);
        ptr = ptr->LINK;
    }
}

