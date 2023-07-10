//Program to implement Binary Search

#include<stdio.h>
#include<stdlib.h>

int Binary_Search(int *ar, int low, int high, int item);

void main(){
    int n, *ar, item, found;

    printf("\n Enter the number of elements to be inputted: ");
    scanf("%d",&n);

    if(n == 0){
        printf("\n No elements to be inputted!");
        exit(0);
    }
    if(n < 0){
        printf("\n Invalid Number!");
        exit(0);
    }

    ar = (int*)malloc(n * sizeof(int));

    printf("\n Input the elements in ascending order: \n");
    getchar();
    for(int i = 0; i < n; i++)
        scanf("%d",&ar[i]);

    printf("\n Enter the element to be found: ");
    scanf("%d",&item);

    found = Binary_Search(ar, 0, n-1, item);

    if(found == -1){
        printf("\n The element is not found!");
    }
    else{
        printf("\n The element is found at position %d",found + 1);
    }

    free(ar);
    
}

int Binary_Search(int *ar, int low, int high, int item){
    if(high > low)
    {
        int mid;
        mid = (low + high)/2;

        if(ar[mid] == item)
            return mid;
        else if(ar[mid] > item)
            Binary_Search(ar, low, mid, item);
        else
            Binary_Search(ar, mid+1, high, item);
    }
    else
        return -1;

}