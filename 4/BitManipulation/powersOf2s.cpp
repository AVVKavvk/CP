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
#define ll long long


 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


int n;
cin>>n;

// vector<int> bits;

// while(n!=0){
//     if(n&1) bits.push_back(1);
//     else bits.push_back(0);
//     n=n>>1;
// }
// // reverse(bits.begin(),bits.end());

// ll ans=1;

// for(int i=0;i<bits.size();i++){
//     // cout<<bits[i]<<" ";
//     if(bits[i]==1) {
//         ans=(pow(2,i));
//         cout<<ans<<" ";
//     }
// }

int cnt=-1;
while(n!=0){
    cnt++;
    if(n&1) cout<<( 1<<cnt)<<" ";;
    
    n=n>>1;
}

return 0 ;
}