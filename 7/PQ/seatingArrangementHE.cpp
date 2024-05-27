#include<bits/stdc++.h>
using namespace std ; 
#define pi 3.14
#define fli(a,b) for(long long  i=a;i<b;i++)
#define flj(a,b) for(long long  j=a;j<b;j++)
#define flk(a,b) for(long long  k=a;k<b;k++)
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
#define sza(a) sizeof(a)/sizeof(long long )
#define vec vector<char> 
#define v2e vector <vector<long long > > 
#define v2ec vector <vector<char> >
#define vei vector<long long > 
#define pu(n) push_back( n); 
#define ll long long
#define limit(x) (x.begin(),x.end())

 

int  main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
                                             ////     H E

long long  n,k;
cin>>n>>k;
string str;
cin>>str;

k=min(n,k);
map<long long ,long long >mpp;
priority_queue<pair<long long ,long long >>pq;

pq.push({n,-1});
for(long long  i=1;i<=k;i++){

    auto it=pq.top();
    pq.pop();
    long long  len=it.first;
    long long  s=-1* it.second;
    long long  e=s+len-1;

    long long  mid=s+(e-s)/2;

    if(len%2==0 && str[i-1]=='R' ){
           mid+=1;
    }
    mpp[mid]=i;


    //* [s.....mid.....end]

   if(s!=mid){
    pq.push({mid-s,-1*s});
   }
   if(e!=mid){
    pq.push({e-mid,-1*(mid+1)});
   }
}


long long  q;
cin>>q;

while(q--){
    long long  seat;
    cin>>seat;

    if(mpp.find(seat)==mpp.end()) cout<< -1<<endl;
    else cout<<mpp[seat]<<endl;
}

return 0 ;
};