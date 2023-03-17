#include <bits/stdc++.h>
using namespace std;
int main()
{

    int total_blocks, total_process;
    cin >> total_blocks;
    int block_size[total_blocks];
    for (int i = 0; i < total_blocks; i++)
    {
        cin >> block_size[i];
    }
    cin >> total_process;
    int process_size[total_process];
    for (int i = 0; i < total_process; i++)
    {
        cin >> process_size[i];
    }
    int allocation[total_process];
    memset(allocation, -1, sizeof(allocation));
    
    for (int i = 0; i < total_process; i++)
    {
        for (int j = 0; j < total_blocks; j++)
        {
            if (block_size[j] >= process_size[i])
            {
                allocation[i] = j;
                block_size[j] = 0;
                break;
            }
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < total_process; i++)
    {
        cout << " " << i + 1 << "\t\t" << process_size[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
    return 0;
}