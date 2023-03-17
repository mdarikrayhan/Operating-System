#include <stdio.h>
int main()
{
    int n, pages[50], frame[10], totalframe, count = 0;
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

    int currentframe = 0;
    printf("\nRef string\tf1      f2      f3      Hit/Miss\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t", pages[i]);
        
        int flag = 0;
        for (int k = 0; k < totalframe; k++)
        {
            if (frame[k] == pages[i])
            {
                flag = 1;
            }
        }

        if (flag == 0)// page missing 
        {
            frame[currentframe] = pages[i];
            currentframe = (currentframe + 1) % totalframe;
            
            for (int k = 0; k < totalframe; k++)
            {
                printf("%d\t", frame[k]);
            }
            printf("Miss \n");
            count++;
        }
        else// page hit
        {
            for (int k = 0; k < totalframe; k++)
            {
                printf("%d\t", frame[k]);
            }
            printf("Hit \n");
        }
    }

    printf("\nNo of Missing Page %d", count);
    return 0;
}
