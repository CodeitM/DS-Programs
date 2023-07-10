//Square pattern question

#include<stdio.h>
#include<math.h>

void main(){
    int i,j,n,mid,val;

    printf("\n Rnter the value of n:");
    scanf("%d",&n);
    mid = 2*n;
    val = 2*n-1;

    for(i=1;i<=val;i++)
    {
        for(j=1;j<=val;j++)
        {
            
            if(i+j<=mid){
                if(i<j){
                printf("%d ",(n-i)+1);
                }
                else{
                    printf("%d ",(n-j)+1);
                }
            }
            else{
                if(i<j){
                    printf("%d ",n-(val - j));
                }
                else{
                    printf("%d ",n-(val - i));
                }
            }
            
            
        }
        printf("\n");
    }
}