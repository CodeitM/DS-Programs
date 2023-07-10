//Program to implement Quick Sort Algorithm.

#include<stdio.h>
#include<stdlib.h>

void QuickSort(int n, int ar[n], int l, int r);
int Partition(int n, int ar[n], int l, int r);

void main(){
    
    int n;

    printf("\n Enter the number of elements to be sorted: ");
    scanf("%d",&n);

    if(n == 0){
        printf("\n No numbers are to be inputted! No Sorting!");
        exit(0);
    }

    if(n < 0){
        printf("\n Invalid Number! No Sorting!");
        exit(0);
    }

    int size = n,ar[n];

    printf("\n Input the numbers to be sorted: \n");
    for(int i = 0; i < n; i++){
        scanf("%d",&(ar[i]));
    }
    printf("\n ar[0]=%d ar[n-1]=%d",ar[0],ar[n-1]);
    QuickSort(n, ar, 0, n-1);

    

    printf("\n The Sorted Numbers are: ");
    for(int i = 0; i < size; i++){
            printf("\n %d",ar[i]);
        }

}

void QuickSort(int n, int ar[n], int l, int r){
    if(l < r){
        int q = Partition(n, ar, l, r);
        QuickSort(n, ar, l, q-1);
        QuickSort(n, ar, q+1, r);

    }
}


int Partition(int n, int ar[n], int l, int r){
    int x = ar[r];
    int i = l - 1;
    int j = 0;
    printf("\n l=%d r=%d n=%d x=%d i=%d j=%d",l,r,n,x,i,j);

    while(j <= r-1){
        if(ar[j] <=  x){
            i++;
            int temp = ar[j];
            ar[j] = ar[i];
            ar[i] = temp;
        }
        j++;
    }
    int temp = ar[i+1];
    ar[i+1] = ar[r];
    ar[r] = temp;

    return i+1;
     
}
