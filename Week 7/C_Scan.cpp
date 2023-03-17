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
    vector<int> fhalf, shalf;
    for (int i = 0; i < n; i++)
    {
        if (RQ[i] < initial)
        {
            fhalf.push_back(RQ[i]);
        }
        else
        {
            shalf.push_back(RQ[i]);
        }
    }
    sort(fhalf.begin(), fhalf.end());
    sort(shalf.begin(), shalf.end());
    for (int i = fhalf.size() - 1; i >= 0; i--)
    {
        tmove = tmove + abs(fhalf[i] - initial);
        initial = fhalf[i];
    }
    for (int i = 0; i < shalf.size(); i++)
    {
        tmove = tmove + abs(shalf[i] - initial);
        initial = shalf[i];
    }
    cout << "Total head movement is: " << tmove;
 }