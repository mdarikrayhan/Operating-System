#include <stdio.h>
#include <unistd.h>
int main()
{
    int x=1;
    if(fork()==0)
    {
        printf("Child has x=%d\n", ++x);
    }
    else
    {
        printf("Parent has x=%d\n", --x);
    }
    return 0;
}
//output
//Parent has x=0
//Child has x=2