#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x;

    for(int i=0; i<n; i++)
    {
        cin >> x;
        if(x == 1)
        {
            cout << "HARD\n";
            return 0;
        }
    }

    cout << "EASY\n";
    return 0;
}