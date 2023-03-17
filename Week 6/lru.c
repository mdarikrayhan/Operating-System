#include <stdio.h>
int main()
{
    int n, frame[20], pages[50], totalframe, b[20], c2[20];
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

    int k = 0, misscount = 0;
    printf("\nRef string\tf1      f2      f3      Hit/Miss\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", pages[i]);
        int flag = 0;
        for (int j = 0; j < totalframe; j++)
        {
            if (pages[i] == frame[j])
                flag++;
        }
        if (flag == 0)
        {
            misscount++;
            if (k < totalframe)
            {
                frame[k] = pages[i];
                k++;
                for (int j = 0; j < totalframe; j++)
                    printf("\t%d", frame[j]);
                printf("\t Miss\n");
            }

            else
            {
                for (int r = 0; r < totalframe; r++)
                {
                    c2[r] = 0;
                    for (int j = i - 1; j < n; j--)
                    {
                        if (frame[r] != pages[j])
                            c2[r]++;
                        else
                            break;
                    }
                }
                for (int r = 0; r < totalframe; r++)
                {
                    b[r] = c2[r];
                }
                for (int r = 0; r < totalframe; r++)
                {
                    for (int j = r; j < totalframe; j++)
                    {
                        if (b[r] < b[j])
                        {
                            int temp = b[r];
                            b[r] = b[j];
                            b[j] = temp;
                        }
                    }
                }
                for (int r = 0; r < totalframe; r++)
                {
                    if (c2[r] == b[0])
                    {
                        frame[r] = pages[i];
                    }
                    printf("\t%d", frame[r]);
                }
                printf("\t Miss\n");
            }
        }
        else
        {
            for (int j = 0; j < k; j++)
            {
                printf("\t%d", frame[j]);
            }
            printf("\t Hit\n");
        }
    }
    printf("\nThe no of page faults is %d", misscount);
}
