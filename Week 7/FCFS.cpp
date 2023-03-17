#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, tmove = 0, initial;
    //cout << "\nEnter the number of QUEUE:";
    cin >> n;
    int RQ[n];
    //cout << "\nEnter the QUEUE in sequence:";
    for (int i = 0; i < n; i++)
    {
        cin >> RQ[i];
    }
    //cout << "\nEnter initial head position:";
    cin >> initial;
    for (int i = 0; i < n; i++)
    {
        tmove = tmove + abs(RQ[i] - initial);
        initial = RQ[i];
    }
    cout << "\nTotal head moment is:" << tmove;
    return 0;
}