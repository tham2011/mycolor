#include <stdio.h>
#include <math.h>
int kt_nguyento(int n)
{
    if (n < 2)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    printf("nhap gia tri cho n:");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 2; i < n; i++)
    {
        if (kt_nguyento(i) == 1)
        {
            sum += i;
        }
    }
    printf("tong cac so nguyen to nho hon %d la %d", n, sum);
    return 0;
}