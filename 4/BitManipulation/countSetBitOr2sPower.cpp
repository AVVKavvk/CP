#include<bits/stdc++.h>
using namespace std ; 
#define pi 3.14
#define ll long long


 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


int n;

cin>>n;

   /// //  M1  

   int cnt=0;
   int k=n;
   while(n!=0){
    if(n&1) cnt++;
    n=n>>1;
   }
   cout<<cnt<<endl;

   // // M2
   cout<< __builtin_popcount(k)<<endl;
//    cout<< __builtin_popcount (4);<<endl;
return 0 ;
}