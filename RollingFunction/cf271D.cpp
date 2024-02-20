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


string s,good;
cin>>s>>good;
set<pair<ll,ll>>st;


int k;
cin>>k;

for(int i=0;i<s.size();i++){
   
    int cnt=0;
    ll pr=1;
    ll pr1=1;
    ll hash1=0;
    ll hash=0;
    ll mod=1e9+7;
    for(int j=i;j<s.size();j++){
    //   sub+=s[j];
      if(good[s[j]-'a']=='0') cnt++;
      if(cnt>k) break;
      hash=(hash + ((s[j]-'a'+1)*pr)%mod)%mod;
      pr=(pr*31)%mod;
      hash1=(hash1 + ((s[j]-'a'+1)*pr1)%mod)%mod;
      pr1=(pr1*37)%mod;
      st.insert({hash1,hash});
      }
}
cout<<st.size()<<endl;


return 0 ;
}