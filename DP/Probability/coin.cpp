#include<bits/stdc++.h>
using namespace std ; 


int n;
double arr[3000];
int dp[3000][3001];

double f(int ind,int heads){
    if(ind==n){
        if(heads>(n-heads)) return 1.0;
        return 0;
    }
    if(dp[ind][heads]!=-1) return dp[ind][heads];
    //pick
    double pick=arr[ind]*f(ind+1,heads+1);
    double notPick= (1.0-arr[ind])*f(ind+1,heads);

    return dp[ind][heads]=pick+notPick;

}
 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);



int t=1;
// cin>>t;
while(t--){ 

cin>>n;

for(int i=0;i<n;i++) cin>>arr[i];

memset(dp,-1, sizeof (dp));
cout<<f(0,0);
}
return 0 ;
}