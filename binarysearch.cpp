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
                cout<<"found at index "<<mid;
                cout<<endl<<endl;
                return mid;
            }
            else if(arr[mid] < ele){
                mid += 1;
            }
            else if(arr[mid] > ele){
                mid -= 1;
            }
        }
    }
}

int main(){
    vector<int> arr {1,2,3,4,5,6,7,8,9,0};

    for (auto i=arr.begin(); i<arr.end();i++){
        cout<<*i<<" ";
    }

    cout<<binarySearch(arr, 14);

    return 0;
}