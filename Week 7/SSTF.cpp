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
    int count=0;
    while (count != n)
    {
        int min = INT_MAX, d, index;
        for (int i = 0; i < n; i++)
        {
            d = abs(RQ[i] - initial);
            if (min > d)
            {
                min = d;
                index = i;
            }
        }
        tmove = tmove + min;
        initial = RQ[index];
        RQ[index] = INT_MAX;
        count++;
    }
    cout << "Total head movement is: " << tmove;
    return 0;
}