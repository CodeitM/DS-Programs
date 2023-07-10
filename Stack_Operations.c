//Program to implement stack operations

#include<stdio.h>
#include<stdlib.h>
#define MAX 10         //This is the maximum size of the stack
int IsFull(int top);
int IsEmpty(int top);
void PUSH(int **ar, int *top, int item);
int POP(int **ar, int *top);
void PEEK(int *ar, int top);

void main(){
    int *ar, item, op, pop, top = -1;

    ar = (int*)malloc(MAX * sizeof(int));

    while(1){

        printf("\n Choose the operation to be carried out in the stack: ");
        printf("\n1.PUSH\n2.POP\n3.PEEK\n4.EXIT\n");
        scanf("%d",&op);
        if(op == 4){
            printf("\n Exiting.....");
            free(ar);
            exit(0);
        }

        switch(op){
            case 1:
            {
                printf("\n Enter the item to be PUSHED into the stack: ");
                scanf("%d",&item);

                PUSH(&ar, &top, item);

                if(top == MAX-1){
                    printf("\n\nNow the stack is Full!\n")
                }

                break;
            }

            case 2:
            {
                if(IsEmpty(top) == 1){

                    printf("\n The Stack is Empty! Element cannot be popped!");
                }
                else{
                    pop = POP(&ar, &top);
                    printf("\n The element which is popped out is %d",pop);

                    if(top == -1){
                        printf("\n\n Now the Stack is Empty!!\n")
                    }
                }
            
                

                break;
            }

            case 3:
            {
                PEEK(ar, top);

                break;
            }

            default: 
            {
                printf("\n Invalid Option! Try Again.");

                break;
            }
        }
    }
}

int IsFull(int top){

    if(top == MAX-1)
        return 1;
    else
        return 0;
}

int IsEmpty(int top){

    if(top == -1)
        return 1;
    else
        return 0;
}

void PUSH(int **ar, int *top, int item){

    if (IsFull(*top) == 1){

        printf("\n The Satck is Full! This element cannot be inputted!");

        return;
    }
    else{

        *top = *top + 1;
        (*ar)[*top] = item;
        
    }
}

int POP(int **ar, int *top){

    if(IsEmpty(*top) == 1){

        printf("\n The Stack is Empty! Element cannot be popped!");
        return 0;
    }
    else{

        int pop = (*ar)[(*top)];
        *top =*top -1 ;
        return pop;
    }
}

void PEEK(int *ar, int top){

    if(IsEmpty(top) == 1){
        printf("\n The Stack is Empty! No elements in stack!");
        return;
    }
    else{

        printf("\n The element on the top of stack is: %d",ar[top]);
    }
}