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

int countDigitDP(int index,int flag,int cnt,vector<int>num,vector<vector<vector<int>>>&dp,int &k,int&d){
 if(cnt>k) return 0;
if(index==num.size()){
    if(cnt==k){ 
        return 1;
    }
    else return 0;
}
 if(dp[index][flag][cnt]!=-1) return dp[index][flag][cnt];

int limit=num[index];

if(flag==1){
    limit=9;
}
int count=0;

for(int digit=0;digit<=limit;digit++){
    if(digit<num[index]){
      if(digit==d) count+=countDigitDP(index+1,1,cnt+1,num,dp,k,d);
      else count+=countDigitDP(index+1,1,cnt,num,dp,k,d);
    }
    else{
      if(digit==d) count+=countDigitDP(index+1,flag,cnt+1,num,dp,k,d);
      else count+=countDigitDP(index+1,flag,cnt,num,dp,k,d);
    }
}


// for(int digit=0;digit<=limit;digit++){
//     if(flag==1){
//       if(digit==d){
//         count+=countDigitDP(index+1,flag,cnt+1,num,dp,k,d);
//       }
//       else count+=countDigitDP(index+1,flag,cnt,num,dp,k,d);
//     }
//     else if(flag==0){
       
//        if(digit==d){

//         if(digit<num[index]) count+=countDigitDP(index+1,1,cnt+1,num,dp,k,d);
//         else count+=countDigitDP(index+1,0,cnt+1,num,dp,k,d);

//        }
//        else {
//          if(digit<num[index]) count+=countDigitDP(index+1,1,cnt,num,dp,k,d);
//          else count+=countDigitDP(index+1,0,cnt,num,dp,k,d);
//        }
//     }
// }


return dp[index][flag][cnt]= count;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


vector<vector<vector<int>>>dp(19,vector<vector<int>>(2,vector<int>(19,-1)));
int l,r;
int k,d;
cin>>l>>r>>d>>k;

vector<int> right=convertNum(r);
r=countDigitDP(0,0,0,right,dp,k,d);

vector<int> left=convertNum(l-1);                               //? l-1 
dp.assign(19, vector<vector<int>>(2, vector<int>(19, -1)));

l=countDigitDP(0,0,0,left,dp,k,d);
cout<<"output "<< r-l;



return 0 ;
}