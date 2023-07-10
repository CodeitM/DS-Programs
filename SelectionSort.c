//A program to implement Selection Sort

#include<Stdio.h>
#include<stdlib.h>

void Selection_Sort(int n, int **ar);

void main(){
    int n ,*ar ,i;

    printf("\n Enter the number of numbers to be sorted: ");
    scanf("%d",&n);

    ar = (int*)malloc(n * sizeof(int));

    printf("\n Enter the numbers to be sorted: ");
    for(i = 0; i < n; i++)
        scanf("%d",&ar[i]);

    Selection_Sort(n ,&ar);

    printf("\n The sorted numbers: ");
    for(i = 0; i < n; i++)
        printf("\n%d",ar[i]);

    free(ar);

}

void Selection_Sort(int n, int **ar){
    int i ,min ,temp ,j;

    for(i = 0; i < n; i++)
    {
        min = i;

        for(j  = i; j < n; j++)
        {
            if((*ar)[j] < (*ar)[min])         
                min = j;
        }

        if(min != i)
        {
            temp=(*ar)[min];
            (*ar)[min] = (*ar)[i];
            (*ar)[i] = temp;
        }
        
    }
}