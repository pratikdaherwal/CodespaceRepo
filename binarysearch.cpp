#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int ele){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    for (int i=0; i<n;i++){
        int mid = (high+low)/2;

        while (low < high){
            if (arr[mid] == ele){
                return mid;
            }
            else if(arr[mid] < ele){
                mid += 1;
            }
            else{
                mid -= 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr {1,2,3,4,5,6,7,8,9,0};

    for (auto i=arr.begin(); i<arr.end();i++){
        cout<<*i<<" ";
    }

    cout<<"found at index "<<binarySearch(arr, 4)<<endl;

    return 0;
}