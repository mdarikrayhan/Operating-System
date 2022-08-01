/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define rep(i, a, b) for (int i = a; i < (b); i++)
int main()
{
    int n,j=0,k=0,l=0;
    cin >> n;
    int pos[n + 5], neg[n + 5];
    rep(i,0,n)
    {
        int a;
        cin>>a;
        if (a >= 0)
        {
            pos[j] = a;
            j++;
        }
        else
        {
            neg[k] = a;
            k++;
        }
    }
    int arr[j+k];
    rep(i,0,j){
        arr[l]=pos[i];
        l++;
    }
    rep(i,0,k){
        arr[l]=neg[i];
        l++;
    }
    rep(i,0,l){
        cout<<arr[i]<<" ";
    }
    cout<<nl;
    return 0;
}