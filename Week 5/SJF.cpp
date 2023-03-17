#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    char pname[50];
    int btime;
    int atime;
} a[50];

bool btimeSort(node a, node b)
{
    return a.btime < b.btime;
}

bool atimeSort(node a, node b)
{
    return a.atime < b.atime;
}
int main()
{
    int n;
    cout << "Enter number of processes\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].pname;
        cin >> a[i].atime;
        cin >> a[i].btime;
    }
    sort(a, a + n, btimeSort);
    sort(a, a + n, atimeSort);
    int ttime = 0, i;
    int j, tArray[n];
    for (i = 0; i < n; i++)
    {
        j = i;
        while (a[j].atime <= ttime && j != n)
        {
            j++;
        }
        sort(a + i, a + j, btimeSort);
        tArray[i] = ttime;
        ttime += a[i].btime;
    }
    tArray[i] = ttime;

    float averageWaitingTime = 0;
    float averageResponseTime = 0;
    float averageTAT = 0;
    cout << "\n";
    cout << "P.Name  AT\tBT\tCT\tTAT\tWT\tRT\n";
    for (i = 0; i < n; i++)
    {
        cout << a[i].pname << "\t";
        cout << a[i].atime << "\t";
        cout << a[i].btime << "\t";
        cout << tArray[i + 1] << "\t";
        cout << tArray[i] - a[i].atime + a[i].btime << "\t";
        averageTAT += tArray[i] - a[i].atime + a[i].btime;
        cout << tArray[i] - a[i].atime << "\t";
        averageWaitingTime += tArray[i] - a[i].atime;
        cout << tArray[i] - a[i].atime << "\t";
        averageResponseTime += tArray[i] - a[i].atime;
        cout << "\n";
    }
    cout << "\n";
    cout << "\nGantt Chart\n";
    for (i = 0; i < n; i++)
    {
        cout << "|   " << a[i].pname << "   ";
    }
    cout << "\n";
    for (i = 0; i < n + 1; i++)
    {
        cout << tArray[i] << "\t";
    }
    cout << "\n";
    cout << "Average Response time: " << (float)averageResponseTime / (float)n << endl;
    cout << "Average Waiting time: " << (float)averageWaitingTime / (float)n << endl;
    cout << "Average TA time: " << (float)averageTAT / (float)n << endl;
    return 0;
}