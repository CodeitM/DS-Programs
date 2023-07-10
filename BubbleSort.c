//Program to implement bubble sort

#include<stdio.h>
#include<stdlib.h>

void Bubble_Sort(int n, int **ar);

void main(){
    int n, *ar, i;
    
    printf("\n Enter the number of elements to be sorted: ");
    scanf("%d",&n);

    ar = (int*)malloc(n * sizeof(int));

    printf("\n Enter the elements: \n");
    getchar();                               //to avoid the \n character
    for(i = 0; i < n; i++)
        scanf("%d",&ar[i]);

    Bubble_Sort(n ,&ar);

    printf("\n The sorted list is: \n");
    for(i = 0; i < n; i++)
        printf("\n %d",ar[i]);

    free(ar);                               //To remove space allocated to array


}

void Bubble_Sort(int n, int **ar){
    int temp;
    for(int i = n; i > 0; i--)
    {
        for(int j = 1; j < i; j++)
        {
            if((*ar)[j-1] > (*ar)[j])
            {
                temp = (*ar)[j-1];
                (*ar)[j-1] = (*ar)[j];
                (*ar)[j] = temp;
            }
        }
    }

}
