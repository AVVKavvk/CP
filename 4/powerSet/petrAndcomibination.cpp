#include<bits/stdc++.h>
using namespace std ; 
#define pi 3.14
#define ll long long


 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
                                    //?  CF  1097/B

int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++) cin>>arr[i];

for(int num=0;num<(1<<n);num++){

    int sum=0;

    for(int k=0;k<n;k++){
        if((num & (1<<k))==0) sum+=arr[k];
        else sum-=arr[k];
    }

    if(sum%360==0){
        cout<<"YES\n";
        return 0;
    }
}

cout<<"NO\n";
return 0 ;
}