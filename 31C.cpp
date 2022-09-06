#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct classRoomTime{
            int startTime;
            int endTime;
            int groupNumber;
};

/*void printVector(vector<classRoomTime> v){
    printf("The Structure is\n");
    for(int i=0; i<v.size(); i++){
         cout << v[i].startTime  <<" " <<v[i].endTime << " " << v[i].groupNumber << endl;
    }
    cout << endl;
}*/


bool cmp(classRoomTime a, classRoomTime b){
            return a.startTime < b.startTime;
}

int main()
{
    int n, start, end, classroomTimeStructureSize;
    vector<classRoomTime> classRoomTimeVector;
    vector<int> excludedGroup;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {

        scanf("%d", &start);
        scanf("%d", &end);
        classRoomTime tmp;
        tmp. startTime = start;
        tmp.endTime = end;
        tmp.groupNumber = i + 1;
        classRoomTimeVector.push_back(tmp);

    }

    //classroomTimeStructureSize = classRoomTimeVector.size();
    //printVector(classRoomTimeVector);
    sort(classRoomTimeVector.begin(), classRoomTimeVector.end(), cmp);
    //printf("After Sorting ");
    //printVector(classRoomTimeVector);

    for(int i=0;  i<n; i++){
            bool shouldAdd = true;
            int left = 0;
            int right = 1;
        while(right < n){
            if(left == i){
                left = left+1;
                right = right + 1;
            }
            else if(right == i){
                right = right + 1;
            }

            else  if (classRoomTimeVector[left].endTime <= classRoomTimeVector[right].startTime){
                        left = right;
                        right = right + 1;
            }

            else{
                shouldAdd = false;
                break;
            }
        }

        if(shouldAdd){
            excludedGroup.push_back(classRoomTimeVector[i].groupNumber);
        }
    }

    sort(excludedGroup.begin(), excludedGroup.end());

    printf("%d\n", excludedGroup.size());
    if(excludedGroup.size() >= 1)
    {
            int i;
                for(i = 0; i<excludedGroup.size()-1; i++){
                        printf("%d ", excludedGroup[i]);
                }
                printf("%d\n", excludedGroup[i]);

    }

    return 0;
}
