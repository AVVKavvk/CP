#include<bits/stdc++.h>
using namespace std ; 


int n;
double arr[3000];
double dp[3000][3001];

double f(int ind,int heads){
    if(ind==n){
        if(heads>(n-heads)) return 1.0;
        return 0.0;
    }
    if(dp[ind][heads]!=-1.0) return dp[ind][heads];
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
// double arr[5]={0.5,0.4,0.6,0.7,0.2};
// arr[0]=0.5;
// arr[1]=.4;
// arr[2]=.6;
// arr[3]=.7;
// arr[4]=.2;

for (int i = 0; i < 3000; i++) {
    for (int j = 0; j < 3001; j++) {
        dp[i][j] = -1.0;
        }
    }
cout<<f(0,0);
}
return 0 ;
}

//.5 .4 .6 .7 .2