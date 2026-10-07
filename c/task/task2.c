#include <stdio.h>

int main()
{
    int num[10] = {1,2,3,4,5,6,7,8,9,10};
    int number[10];

    for(int i = 0; i < 10; i++)
    {
        number[i] = num[i];
    }

    printf("Original Array:\n");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", num[i]);
    }

    printf("\nCopied Array:\n");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", number[i]);
    }

    return 0;
}