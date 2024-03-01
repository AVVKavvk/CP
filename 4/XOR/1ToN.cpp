#include<bits/stdc++.h>
using namespace std ; 
#define pi 3.14
#define ll long long


 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


int n;
cin>>n;

if(n%4==0) cout<<n<<endl;
if(n%4==1) cout<<1<<endl;
if(n%4==3) cout<<0<<endl;
if(n%4==2) cout<<n+1<<endl;
return 0 ;
}