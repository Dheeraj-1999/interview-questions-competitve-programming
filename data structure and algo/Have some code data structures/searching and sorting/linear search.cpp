#include <stdio.h>
int main()
{
    int a[10], i, item;
    printf("\nEnter SEVEN elements of an array:\n");
    for (i=0; i<=6; i++)
        scanf("%d", &a[i]);
    printf("\nEnter item to search: ");
    scanf("%d", &item);
    for (i=0; i<=9; i++)
        if (item == a[i])
        {
            printf("\nItem found at location %d", i+1);
            break;
        }
    if (i > 9)
        printf("\nItem does not exist.");
    return 0;
}
