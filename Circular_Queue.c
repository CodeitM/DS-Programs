//Program to implement Circular Queue

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void ENQUEUE(int **ar, int *front, int *rear, int item);
int DEQUEUE(int **ar, int *front, int *rear);
void DISPLAY(int *ar, int *front, int *rear);

void main(){
    int *ar, front = -1, rear = -1, op, item, dequeue;

    ar = (int*)malloc(MAX * sizeof(int));

    while(1){

        printf("\n Enter the operation to be performed on the circular queue: ");
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&op);

        if(op == 4){
            printf("\n Exiting.....");
            free(ar);
            exit(0);
        }

        switch(op){
            case 1: 
            {
                printf("\n Enter the item to be inputted into the circular queue: ");
                scanf("%d",&item);

                ENQUEUE(&ar, &front, &rear, item);

                break;
            }

            case 2:
            {
                dequeue = DEQUEUE(&ar, &front, &rear);

                if(dequeue != -1){
                     printf("\n The item removed from the circular queue is: %d",dequeue);
                }

                break;
            }

            case 3:
            {
                DISPLAY(ar, &front, &rear);

                break;
            }

            default:
            {
                printf("\n InValid Option! Try Again!");

                break;
            }
        }
    }   
}

void ENQUEUE(int **ar, int *front, int *rear, int item){

    if((*rear +1) % MAX == *front ){
        printf("\n The Circular Queue has reached its maximum limit. Cannot input elements!");
        return;
    }
    else{
        if(*front == -1){
            *front = 0; 
            *rear = 0;
        }
        else{
             *rear = (*rear + 1) % MAX;
        }
       
        (*ar)[*rear] = item;
    
    }
}

int DEQUEUE(int **ar, int *front, int *rear){

    if(*rear == -1){
        printf("\n The Queue is empty! ELements cannot be removed!");
        return -1;              // Assuming that the elements on the queue are non negative
    }
    else{
        
        int dequeue = (*ar)[*front];
        if( *front == *rear){
            *front = -1;
            *rear = -1;
        }
        else{
            *front = (*front + 1) % MAX;
        }

        return dequeue;
    }
}

void DISPLAY(int *ar, int *front, int *rear){

    if(*rear == -1){
        printf("\n The Queue is Empty!");
        return;
    }

    else{
        printf("\n The elements in the queue are: ");
        for(int i = *front; i <= *rear; i = (i+1) % MAX){
            printf("\n %d",ar[i]);

            if(i == *rear)
                break;
        }
    }
    

}