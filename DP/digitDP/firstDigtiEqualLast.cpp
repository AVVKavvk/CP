#include<bits/stdc++.h>
using namespace std ; 
#define pi 3.14
#define fli(a,b) for(int i=a;i<b;i++)
#define flj(a,b) for(int j=a;j<b;j++)
#define flk(a,b) for(int k=a;k<b;k++)
#define ma(a,b)      ( (a) > (b) ? (a) : (b)); 
#define mi(a,b)      ( (a) < (b) ? (a) : (b)) ;
#define pb push_back 
#define pob pop_back 
#define sz size() 
#define p2s(a,b) std::cout <<a<<' ' << b << std::endl ;
#define pn(a) std::cout <<a << std::endl ;
#define nl std::cout << std::endl ;
#define p(a) std::cout <<a ;
#define ps(a) std::cout <<a<< ' ' ;
#define cig(arr,n)   cin.getline(arr,n) 
#define sza(a) sizeof(a)/sizeof(int)
#define vec vector<char> 
#define v2e vector <vector<int> > 
#define v2ec vector <vector<char> >
#define vei vector<int> 
#define pu(n) push_back( n); 


vector<int> convertNum(int n){
    vector<int>temp;
    while(n>0){
        temp.push_back(n%10);
        n=n/10;
    }

    reverse(temp.begin(),temp.end());
    return temp;
}

int sameDigit(int index,int flag,int first,int last ,vector<int>num,vector<vector<vector<vector<int>>>>&dp){

if(index==num.size()){
    if(first==last){ 
        return 1;
    }
    else return 0;
}
 if(dp[index][flag][first][last]!=-1) return dp[index][flag][first][last];

int limit=num[index];

if(flag==1){
    limit=9;
}
int count=0;

for(int digit=0;digit<=limit;digit++){
    if(digit<num[index]){
        if(first==0) count+=sameDigit(index+1,1,digit,digit,num,dp);
        else count+=sameDigit(index+1,1,first,digit,num,dp);
    }
    else{
        if(first==0) count+=sameDigit(index+1,flag,digit,digit,num,dp);
        else count+=sameDigit(index+1,flag,first,digit,num,dp);
    }
}
// for(int digit=0;digit<=limit;digit++){
//   if(flag==1){
//          if(first==0){
//             count+=sameDigit(index+1,1,digit,digit,num,dp);
//          }
//          else {
//             count+=sameDigit(index+1,1,first,digit,num,dp);
//          }
//   }
//   else{
//     if(digit<num[index]){
//         if(first==0){
//                     count+=sameDigit(index+1,1,digit,digit,num,dp);
//                 }
//                 else {
//                     count+=sameDigit(index+1,1,first,digit,num,dp);
//                 }
//             }
//     else{
//         if(first==0){
//                     count+=sameDigit(index+1,0,digit,digit,num,dp);
//                 }
//                 else {
//                     count+=sameDigit(index+1,0,first,digit,num,dp);
//                 }
//     }
//   }
// }
return dp[index][flag][first][last]= count;
}



int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


vector<vector<vector<vector<int>>>>dp(19,vector<vector<vector<int>>>(2,vector<vector<int>>(10,vector<int>(10,-1))));
int l,r;
cin>>l>>r;
vector<int> right=convertNum(r);
r=sameDigit(0,0,0,0,right,dp);
vector<int> left=convertNum(l-1);
dp.assign(19,vector<vector<vector<int>>>(2,vector<vector<int>>(10,vector<int>(10,-1))));

l=sameDigit(0,0,0,0,left,dp);
cout<< r-l<<endl;



return 0 ;
}


// 12 1122345