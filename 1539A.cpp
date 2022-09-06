#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int TC;
    long long int n, x, t, z, ans;
    scanf("%d", &TC);

    while(TC--)
    {
            scanf("%I64d %I64d %I64d", &n, &x, &t);
            z = t/x;

            if(z>n)
            {
                ans = ((n) *  (n-1)) /2;
            }
            else{
                ans = z*n;
                ans = ans  - (((z)*(z+1))/2);
            }

            printf("%I64d\n", ans);
    }

    return 0;
}
