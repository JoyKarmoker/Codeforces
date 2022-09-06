#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


void printVectorofPair(vector<pair<long long int, long long int>> v){
    printf("The Vector is: \n");
    for(pair<long long int, long long int> p: v){
        cout << p.first << " " <<p.second << endl;
    }
    return;
}


int main()
{
    int n, left = 0, right = 1, nodeRemove = 0, ans = 1, temp;
    long long int first, second;
    vector<pair<long long int, long long int>> v;
    scanf("%d", &n);
    temp = n;
    while(temp--)
    {
            scanf("%I64d %I64d", &first, &second);
            v.push_back({first, second});
    }

    //sortVector(v);
    sort(v.begin(),  v.end());
    //printf("After Sort ");
    //printVectorofPair(v);

while(right < n){
        if(v[left].second < v[ right].first){ //Non Overlaping Case
            left = right;
            right = right + 1;
        }
        else if(v[left].second >= v[right].first &&v[left].second < v[right].second){ //Remove Right Interval
                    right = right+1;
                    nodeRemove = nodeRemove + 1;
        }
        else{ //Remove Left Interval
            left = right;
            right = right+1;
            nodeRemove = nodeRemove+1;
        }
    }

    ans = n-nodeRemove;
    //printf("Node Remove = %d\n", nodeRemove);

    printf("%d\n", ans);

    return 0;
}
