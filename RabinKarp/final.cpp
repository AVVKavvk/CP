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
#define limit(x) (x.begin(),x.end())


 ll prR=1;
 ll prL=1;
 int cnt=0;
 vector<int>ans;
 ll mod=1000000000+7;

 ll computeHash(string s){
    ll pr=1;
    ll hash=0;
    for(auto it:s){
        hash = (hash + ((it-'a'+1)*pr)%mod)%mod;
        pr=(pr*31)%mod;
    }
    prR=pr; 
    return hash;
 }
 void rabinKarp(string s, string pat){
   ll pathHash= computeHash(pat);
   int n1=pat.size();
   int n2=s.size();

   ll hash=computeHash(s.substr(0,n1));
   if(hash==pathHash) {ans.push_back(1);cnt++;}

   int left=0;
   int right=n1-1;
   while(right<n2-1){
         right++;
         hash=( hash + (((s[right]-'a')+1 )*prR)%mod)%mod;
         hash=( hash - (((s[left]-'a')+1 )*prL)%mod)%mod;
         prR=(prR*31)%mod;
         prL=(prL*31)%mod; 
         left++;
         pathHash= (pathHash*31)%mod;
         if(hash<0) hash=hash+mod;                           //?    learn
         if(pathHash==hash) {
            cnt++;
            ans.push_back(left+1);
         }
   }
 }

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string s,path;
cin>>s>>path;
rabinKarp(s,path);
cout<<cnt;


return 0 ;
}