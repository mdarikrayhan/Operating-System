#include <stdio.h>
void main()
{
    int frame[15], pages[100], change[15], totalframe, n, i, j, k, l, index, misscount = 0, temp, flag = 0, flag1 = 0, found, max;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the page numbers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &totalframe);

    for (int i = 0; i < totalframe; i++)
    {
        frame[i] = -1;
    }

    printf("\nRef string\tf1      f2      f3      Hit/Miss\n");
    for (j = 0; j < n; j++)
    {
        printf("%d\t", pages[j]);
        flag = 0;
        flag1 = 0;
        for (i = 0; i < totalframe; i++)
        {
            if (frame[i] == pages[j])
            {
                flag = 1;
                flag1 = 1;
                break;
            }
        }
        if (flag == 0)
        {

            for (i = 0; i < totalframe; i++)
            {
                if (frame[i] == -1)
                {
                    frame[i] = pages[j];
                    misscount++;
                    flag1 = 1;
                    break;
                }
            }
        }

        if (flag1 == 0)
        {
            for (i = 0; i < totalframe; i++)
            {
                change[i] = 0;
            }

            for (i = 0; i < totalframe; i++)
            {
                for (k = j + 1; l <= n; k++)
                {
                    if (frame[i] == pages[k])
                    {
                        change[i] = k - j;
                        break;
                    }
                }
            }
            found = 0;

            for (i = 0; i < totalframe; i++)
            {
                if (change[i] == 0)
                {
                    index = i;
                    found = 0;
                    break;
                }
            }
            if (found == 0)
            {
                max = change[0];
                index = 0;

                for (i = 1; i < totalframe; i++)
                {
                    if (max < change[i])
                    {
                        max = change
                            [i];
                        index = i;
                    }
                }
            }
            frame[index] = pages[j];
            misscount++;
        }

        for (int i = 0; i < totalframe; i++)
        {
            printf("\t%d", frame[i]);
        }
        if (flag == 1 && flag1 == 1)
        {
            printf("\tHit\n");
        }
        else
        {
            printf("\tMiss\n");
        }
    }

    printf("\nThe no of page faults is %d", misscount);
}