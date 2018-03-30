#include<stdio.h>
int main(void)
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int max,min,a,i;
    i = 3;
    scanf("%d",&min);
    scanf("%d",&max);
    while (scanf("%d", &a) != EOF)
    {       
        if(i%2)
        {
            if(a < min)
                min = a;
        }
        else
            if(a > max)
                max = a;
        i++;
    }
    printf("%d",min + max);
}
