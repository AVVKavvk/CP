#include<bits/stdc++.h>
using namespace std ; 
#define pi 3.14
#define ll long long


 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;
int k;
cin>>k;

if((n & (1<<k))==0) cout<<"Not Set Bit\n";
else cout<<"Set Bit\n";

return 0 ;
}