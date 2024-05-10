#include <stdio.h>
int main(){
    int N;
    printf ("nhap so nguyen duong N");
    scanf ("%d",&N);
    int sum =0;
    for (int i=2;i<=N;i+=2)
    {
        sum +=1;
        if(i!=N)
        {
          printf ("%d +",i);
        }
        else
        {
            printf ("%d=",i);
        }
    }
    printf ("%d\n",sum);
    return 0;
}