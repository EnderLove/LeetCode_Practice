#include <stdio.h>

int addTwoNumbers(int list1[], int list2[], int size1, int size2)
{
    // We dont know the size of the list
    // The elements are not consecutive

    int reverse = 0;

    for (int i = 0; i < size1; i++)
    {
        if (list1[i + 1] != '\0')
        {
            reverse += list1[i] * (i * 10);
            //reverse += list1[i];
        }
        else
        {
            //reverse += list1[i];
        }  
    }

    return reverse;
}

int main()
{
    int list1[3] = {2, 4, 3};
    int list2[3] = {5, 6, 4};

    int size1 = sizeof(list1) / sizeof(list1[0]);
    int size2 = sizeof(list2) / sizeof(list2[0]);

    int num = addTwoNumbers(list1, list2, size1, size2); // 342 + 465 = 807

    printf("Number: %d\n", num);

    return 0;
}