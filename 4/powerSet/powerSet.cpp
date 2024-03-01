#include<bits/stdc++.h>
using namespace std ; 
#define pi 3.14
#define ll long long


 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;

int arr[n];
for(int i=0;i<n;i++) cin>>arr[i] ; 

vector<vector<int>>ans;

for(int num=0;num<(1<<n);num++){

    vector<int>temp;

    for(int k=0;k<n;k++){
        if((num &(1<<k))!=0) temp.push_back(arr[k]);
    }
    ans.push_back(temp);
}


for(auto it:ans){
    for(auto j:it){
        cout<<j<<' ';
    }
    cout<<endl;
}

return 0 ;
}