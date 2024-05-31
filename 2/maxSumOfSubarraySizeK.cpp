//{ Driver Code Starts

//? https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1


#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        long sum=0;
        for(int i=0;i<=k-1;i++){
            sum+=arr[i];
        }
        
        long maxi=sum;
        int l=0;int r=k-1;
        while(r<n-1){
            r++;
            sum+=arr[r];
            sum-=arr[l];
            maxi=max(sum,maxi);
            l++;
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends