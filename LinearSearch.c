//Program to implement linear search without searching repeated elements

#include<stdio.h>
#include<stdlib.h>

int LinearSearch(int *ar, int n, int item);

void main(){
    int *ar, n, item, found;

    printf("\n Enter the number of elements to be inputted: ");
    scanf("%d",&n);

    if(n == 0)
    {
        printf("\n No Numbers are Inputted!");
        exit(0);
    }

    if(n < 0)
    {
        printf("\n InValid Number!");
        exit(0);
    }

    ar = (int*)malloc(n * sizeof(int));

    printf("\n Enter the elements: \n");
    for(int i = 0; i < n; i++)
        scanf("%d",&ar[i]);

    printf("\n Enter the element to be searched for: ");
    scanf("%d",&item);

    found = LinearSearch(ar, n, item);

    if(found != -1)
        printf("\nThe item %d is found at position %d!",item,found + 1);
    else
        printf("\nThe item %d is not found! \n",item);

    free(ar);

}

int LinearSearch(int *ar, int n, int item){
    for(int i = 0; i < n; i++)
    {
        if(ar[i] == item)
            return i;
    }

    return -1;
}