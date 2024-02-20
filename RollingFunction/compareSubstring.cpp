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

ll prefix[1000005];

ll power(int base,int n,int mod)
{ if(n<0) return 1;
   ll ans=1;
   while(n){
    if(n%2){
        n=n-1;
        ans=(ans*base)%mod;
    }
    else {
        base=(base*base);
        n=n/2;
    }
   }
   return ans;
} 


// int computeHash(string s){
//     ll pr=1;
//     int hash=0;
//     int mod=1e9+7;

//     for(auto i:s){
//         hash=(hash+ ((i-'a'+1)*pr)%mod)%mod;
//         pr=(pr*31)%mod;
//     }
//     return hash;
// }

ll calHash(int l,int r){
    int mod=1e9+7;
    ll hash=prefix[r];
    if(l>0) hash= (hash- (prefix[l-1])+mod)%mod;
    
    hash= (hash * power(power(31,l,mod),mod-2,mod));
    
    return hash;

}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

string s;
cin>>s;
    ll pr=1;
    ll hash=0;
    int mod=1e9+7;
for(int i=0;i<s.size();i++){
    hash=(hash+ ((s[i]-'a'+1)*pr)%mod)%mod;
    prefix[i]=hash;
    pr=(pr*31)%mod;
}

// cout<<prefix[0];cout<<endl<<prefix[1]<<endl<<prefix[2];
int q;
cin>>q;
while(q--){
    int i1,j1,i2,j2
;
cin>>i1>>j1>>i2>>j2;

ll hash1=calHash(i1,j1);
ll hash2=calHash(i2,j2);

cout<<hash1<<" "<<hash2<<endl;
if(hash1==hash2) cout<<"YES\n";
else cout<<"NO\n";

}
return 0 ;
}