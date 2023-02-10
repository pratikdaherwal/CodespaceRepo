#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&arr){
    int n = arr.size();
    for (int i=0; i<n-1; i++){
        for (int j=0; j<(n-1)-i; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(vector<int>&arr){
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        int minpos = i;
        for(int j=i+1; j<n; j++){
            if (arr[minpos] > arr[j])
                minpos = j;
        }
        int temp = arr[minpos];
        arr[minpos] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    vector<int> arr {3,4,56,7,4,2,1,22,11,21};
    for(auto i=arr.begin(); i<arr.end(); i++){
        cout<<*i<<" ";
    }

    selectionSort(arr);
    cout<<endl;
    for(auto i=arr.begin(); i<arr.end(); i++){
        cout<<*i<<" ";
    }
    cout<<"\n";
    return 0;
}
