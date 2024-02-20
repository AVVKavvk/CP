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

ll parent[200005];

 int findParent(int node){
    if(parent[node]==node) return node;
    else return parent[node]=findParent(parent[node]);
 }
 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

vector<pair<int,pair<int,ll>>>store;
int n,q;
cin>>n>>q;
fli(1,n+2) {       //*     importent 
    parent[i]=i;
}
// cout<<"kumawat" ;
while(q--){
// cout<<"vipin";
    int l,r;
    ll color;
    cin>>l>>r>>color;
    store.push_back({l,{r,color}});
    
}
// cout<<" vipin ";
vector<int>ans(n+1);
// int k=q;
reverse(store.begin(),store.end());
// cout<<store.size();
for(auto it:store){
    int l=it.first;
    int r=it.second.first;
    ll color=it.second.second;
    int i=findParent(l);
    while(i<=r){
        ans[i]=color;
        parent[i]=i+1;
        
        i=findParent(parent[i]);
    }
}
for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
return 0 ;
}