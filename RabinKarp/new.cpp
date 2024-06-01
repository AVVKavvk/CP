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
 
 ll prR=1;
 int mod=1e9+7;
 ll computeHash(string s){
    ll hash=0;
    ll pr=1;
    for(auto ch:s){
        hash=(hash+ ((ch-'a'+1)*pr)%mod)%mod;
        pr=(pr*31)%mod;
    }
    prR=pr;
    return hash;
 }
void calculateOccurance(string s,string t){
  ll hash1=computeHash(t);
  ll hash2=computeHash(s.substr(0,t.size()));
  ll cnt=0;
  vector<pair<int,int>>temp;
  if(hash1==hash2){
    cnt++;
    temp.push_back({0,t.size()-1});
  }
  int l=0;
  int r=t.size();
  ll pr=1;
  while(r<s.size()){
    hash2=(hash2 + ((s[r]-'a'+1)*prR)%mod)%mod;
    r++;
    hash2=(hash2 - ((s[l]-'a'+1)*pr)%mod)%mod;
    l++;
    if(hash2<0) hash2=hash2+mod;
    pr=(pr*31)%mod;
    prR=(prR*31)%mod;
    hash1=(hash1*31)%mod;
    if(hash1==hash2){
        cnt++;
        temp.push_back({l,r-1});
    }
  }

  cout<<cnt<<endl;

  for(auto it:temp){
    cout<<it.first<<" "<<it.second<<endl;
  }

}
 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);



int t=1;
// cin>>t;
while(t--){ 
string s;
string t;
cin>>s>>t;

calculateOccurance(s,t);

}
return 0 ;
}