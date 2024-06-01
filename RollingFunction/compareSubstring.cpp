#include<bits/stdc++.h>
using namespace std ; 
#define pi 3.14
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define fk(a,b) for(int k=a;k<b;k++)
#define pb push_back 
#define pob pop_back 
#define nl std::cout << std::endl ;
#define ll long long
#define limit(x) x.begin(),x.end()


ll bTD(){ string s;cin>>s;ll num=0;
for(auto ch:s){if(ch=='1')num = num*2 + 1;else num=num*2;}
return num;}; 
bool pOf2(ll num){if(num<=0) return false;if((num&(num-1))==0) return true;else return false;}
 
ll prefix[1000006];
 int mod=1e9+7;


ll power(ll base,int n){
    ll ans=1;
    while(n>0){
        if(n&1){
            ans=(ans*base)%mod;
            n--;
        }
        else{
            n=n>>1;
            base=(base*base)%mod;
        }
    }
    return ans;
}

ll computeHash(int l,int r){
    ll hash=0;
    hash=prefix[r];
    if(l-1>=0) hash=(hash - prefix[l-1])%mod;
    if(hash<0)hash+=mod;
    hash = (hash * power(power(31,l),mod-2))%mod;
    return hash;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);




int t=1;
// cin>>t;
while(t--){ 
string s;
cin>>s;

ll hash=0;
ll pr=1;

for(int i=0;i<s.size();i++){
    hash=(hash + ((s[i]-'a'+1)*pr)%mod)%mod;
    pr=(pr*31)%mod;
    prefix[i]=hash;
}

int q;
cin>>q;
while(q--){
    int i1,j1,i2,j2;
    cin>>i1>>j1>>i2>>j2;
    ll hash1=computeHash(i1,j1);
    ll hash2=computeHash(i2,j2);
    cout<<hash1<<"  "<<hash2<<endl;
    if(hash1==hash2) cout<<"Yes\n";
    else cout<<"No\n";

}

}
return 0 ;
}