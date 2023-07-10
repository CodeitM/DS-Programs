//To implement LinearSearch with Repetition of elements


#include<stdio.h>
#include<stdlib.h>

void Linear_Search(int *ar, int n, int item);

void main(){
    int *ar, n, item;

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

    Linear_Search(ar, n, item);

    free(ar);

}

void Linear_Search(int *ar, int n, int item){
    int count=0;

    for(int i = 0; i < n; i++)
    {
        if(ar[i] == item)
        {
            printf("\n The item is found at position %d",i + 1);
            count++;
        }
    }

    if(count == 0)
        printf("\n The item %d id not found!",item);
        
}