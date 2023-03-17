#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int processes[n];
    int bt[n];
    int wt[n];
    int tat[n];
    int total_wt = 0;
    int total_tat = 0;
    cout<<"Enter the processes and burst time"<<endl;
    for (int i = 0; i < n; i++)
    {
        processes[i] = i + 1;
        cin >> bt[i];
    }
    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];

    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    cout << "Processes "
         << " Burst time "
         << " Waiting time "
         << " Turn around time\n";

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i + 1 << "\t\t" << bt[i] << "\t "
             << wt[i] << "\t\t " << tat[i] << endl;
    }
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
    return 0;
}
