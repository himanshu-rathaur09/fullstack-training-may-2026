#include <stdio.h>

int main()
{
    int num[10] = {1,2,3,4,5,6,7,8,9,10};
    int even[10];
    int count = 0;

    for(int i = 0; i < 10; i++)
    {
        if(num[i] % 2 == 0)
        {
            even[count] = num[i];
            count++;
        }
    }

    printf("Even numbers are:\n");

    for(int i = 0; i < count; i++)
    {
        printf("%d ", even[i]);
    }

    return 0;
}