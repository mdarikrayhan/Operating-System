#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<pair<int, int>, int>> process;
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int at, bt, p;
        cout << "Enter Process ID: ";
        cin >> p;
        cout << "Enter Arrival Time: ";
        cin >> at;
        cout << "Enter Burst Time: ";
        cin >> bt;
        process.push_back({{at, bt}, p});
    }
    sort(process.begin(), process.end());
    int processes[n], bt[n], at[n];
    for (int i = 0; i < n; i++)
    {
        processes[i] = process[i].second;
        at[i] = process[i].first.first;
        bt[i] = process[i].first.second;
    }

    int wt[n], tat[n], ct[n], rt[n];
    // find waiting time of all processes
    int start_time[n];
    start_time[0] = at[0]; // first start time is when the first process arrives
    wt[0] = 0;             // first process waiting time is 0
    for (int i = 1; i < n; i++)
    {
        start_time[i] = start_time[i - 1] + bt[i - 1]; // start time is the last process start time plus its burst time
    }
    for (int i = 1; i < n; i++)
    {
        wt[i] = start_time[i] - at[i]; // waiting time is the start time minus the arrival time
        if (wt[i] < 0)
            wt[i] = 0;
    }

    // find turn around time for all processes
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
    // find completion time for all processes
    for (int i = 0; i < n; i++)
    {
        ct[i] = tat[i] + at[i];
    }
    // find response time for all processes
    for (int i = 0; i < n; i++)
    {
        rt[i] = start_time[i] - at[i];
    }

    // Display processes along with all details
    cout << "Processes "
         << " Burst Time "
         << " Arrival Time "
         << " Waiting Time "
         << " Turn-Around Time "
         << " Completion Time "
         << "Response Time" << endl;
    int total_wt = 0, total_tat = 0, total_ct = 0, total_rt = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        total_ct = total_ct + ct[i];
        total_rt = total_rt + rt[i];
        int compl_time = tat[i] + at[i];
        cout << " " << i + 1 << "\t\t" << bt[i] << "\t\t"
             << at[i] << "\t\t" << wt[i] << "\t\t "
             << tat[i] << "\t\t " << compl_time <<"\t\t"<<rt[i]<< endl;
    }

    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
    cout << "\nAverage completation = "
         << (float)total_ct / (float)n;
    cout << "\nAverage response time = "
         << (float)total_rt / (float)n;
    cout << "\n\n";

    for (int i = 0; i <= ct[n - 1]; i++)
    {
        cout << "_";
    }
    cout << endl;

    int d = 0;
    cout << '|';
    for (int i = 0; i <= ct[n - 1]; i++)
    {
        if (i == ct[d])
        {
            cout << "|";
            d++;
        }
        else
        {
            cout << " ";
        }
    }
    cout << endl;
    int f = 0;
    cout << '|';
    for (int i = 0; i <= ct[n - 1]; i++)
    {
        if (i == ct[f])
        {
            cout << "|";
            f++;
        }
        else
        {
            cout << " ";
        }
    }
    cout << endl;
    for (int i = 0; i <= ct[n - 1]; i++)
    {
        cout << "-";
    }
    cout << endl;

    cout << setw(ct[0] + 1) << processes[0];
    for (int i = 1; i < n; i++)
    {
        cout << setw(ct[i] - ct[i - 1]) << processes[i];
    }
    cout << endl;
    return 0;
}
