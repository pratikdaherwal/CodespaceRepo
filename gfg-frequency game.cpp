
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        unordered_map<int, int> map;
        int mini = INT_MAX;
        int ans = -1;
        
        for(int i=0; i<n; i++){
            map[arr[i]]++;
        }
        
        for(auto i:map){
            if(i.second < mini){
             mini = i.second;
             ans = i.first;
            }
            
            if(i.second == mini){
                ans = max(ans, i.first);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends