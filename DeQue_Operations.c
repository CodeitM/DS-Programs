//Program to implement double ended queue(DeQue)

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

void ENQUEUE_REAR(int **ar, int *front, int *rear, int item);
void ENQUEUE_FRONT(int **ar, int *front, int *rear, int item);
int DEQUEUE_FRONT(int **ar, int *front, int *rear);
int DEQUEUE_REAR(int **ar, int *front, int *rear);
void DISPLAY(int *ar, int *front, int *rear);

void main(){
    int *ar, front = -1, rear = -1, op, item, dequeue;

    ar = (int*)malloc(MAX * sizeof(int));

    while(1){

        printf("\n Enter the operation to be performed on the queue: ");
        printf("\n1.ENQUEUE REAR\n2.ENQUEUE FRONT\n3.DEQUEUE FRONT\n4.DEQUEUE REAR \n5.DISPLAY\n6.EXIT\n");
        scanf("%d",&op);

        if(op == 6){
            printf("\n Exiting.....");
            free(ar);
            exit(0);
        }

        switch(op){
            case 1: 
            {
                printf("\n Enter the item to be inputted into the queue: ");
                scanf("%d",&item);

                ENQUEUE_REAR(&ar, &front, &rear, item);

                break;
            }

            case 2:{
                printf("\n Enter the item to be inputted into the queue: ");
                scanf("%d",&item);

                ENQUEUE_FRONT(&ar, &front, &rear, item);

                break;
            }

            case 3:
            {
                dequeue = DEQUEUE_FRONT(&ar, &front, &rear);

                if(dequeue != -1){
                     printf("\n The item removed from the queue is: %d",dequeue);
                }

                break;
            }

            case 4:
            {
                dequeue = DEQUEUE_REAR(&ar, &front, &rear);

                if(dequeue != -1){
                    printf("\n The item removed from the queue is: %d",dequeue);
                }

                break;
            }

            case 5:
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

void ENQUEUE_REAR(int **ar, int *front, int *rear, int item){

    if(*rear == MAX-1){
        printf("\n The Queue has reached its maximum limit. Cannot input elements!");
        return;
    }
    
    else{
        if(*front == -1){
            *front = 0; 
        }

        *rear = *rear + 1;
        (*ar)[*rear] = item;
    
    }
}

void ENQUEUE_FRONT(int **ar, int *front, int *rear, int item){

    if(*front == 0){
        printf("\nCannot input elements into the DeQue from front as front is occupied !");
        return;
    }
    
    else{
        if(*front == -1){
            *front = 0; 
            *rear = 0;
        }
        else{
            *front = *front - 1;
            (*ar)[*front] = item;
        }
    
    }
}

int DEQUEUE_FRONT(int **ar, int *front, int *rear){

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
            *front = *front + 1;
        }

        return dequeue;
    }
}
int DEQUEUE_REAR(int **ar, int *front, int *rear){

    if(*rear == -1){
        printf("\n The Queue is empty! ELements cannot be removed!");
        return -1;              // Assuming that the elements on the queue are non negative
    }
    else{
        
        int dequeue = (*ar)[*rear];
        if( *front == *rear){
            *front = -1;
            *rear = -1;
        }
        else{
            *rear = *rear - 1;
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
        for(int i = *front; i <= *rear; i++){
            printf("\n %d",ar[i]);
        }
    }
    

}