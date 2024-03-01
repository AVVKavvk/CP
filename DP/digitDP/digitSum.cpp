#include<bits/stdc++.h>
using namespace std ; 



vector<int> convertNum(long long n){
    vector<int>temp;
    while(n>0){
        temp.push_back(n%10);
        n=n/10;
    }

    reverse(temp.begin(),temp.end());
    return temp;
}

long long sumDigit(int index,int flag,int sum,vector<int>num,vector<vector<vector<long long>>> &dp){

if(index==num.size()){
   return sum;
}
 if(dp[index][flag][sum]!=-1) return dp[index][flag][sum];

int limit=num[index];

if(flag==1){
    limit=9;
}
long long count=0;

for(int digit=0;digit<=limit;digit++){
    if(flag==1){
      count+=(sumDigit(index+1,1,sum+digit,num,dp));
    }
    else if(flag==0){
       if(digit<num[index] ) count+=(sumDigit(index+1,1,sum+digit,num,dp));
       else count+=(sumDigit(index+1,0,sum+digit,num,dp));
    }
}
return dp[index][flag][sum]= count;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);



long long l,r;
int t;
cin>>t;
while(t--){


cin>>l>>r;

vector<vector<vector<long long>>>dp(19,vector<vector<long long>>(2,vector<long long>(170,-1)));
vector<int> right=convertNum(r);
r=sumDigit(0,0,0,right,dp);
vector<int> left=convertNum(l-1);
dp.assign(19,vector<vector<long long>>(2,vector<long long>(170,-1)));

l=sumDigit(0,0,0,left,dp);
cout<<r-l<<endl;
}


return 0 ;
}