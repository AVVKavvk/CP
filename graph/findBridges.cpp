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

int tin[1000006];
int mini[100006];

int vis[1000006];

int cnt=0;
int t=1;

void printBridges(int child,int par){
    cout<<child<<" "<<par<<endl;
}

void findBridges(int node,int parent,vector<int> adj[]){
vis[node]=1;
tin[node]=mini[node]=t++;

for(auto it:adj[node]){
    if(it==parent) continue;

    if(vis[it]==0){
       findBridges(it,node,adj);
       mini[node]=min(mini[node],mini[it]);

       if(mini[it]>tin[node]){                                 // ?
        cnt++;
        printBridges(it,node);
        // cout<<it<<" "<<node<<endl;
       }
    }
    else{
          mini[node]=min(mini[node],tin[it]);
    }

}
}
 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


int n,m;
cin>>n>>m;


vector<int> adj[n+1];   // ?

for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;

    adj[u].pb(v);
    adj[v].pb(u);
}
nl;
findBridges(1,0,adj);
cout<<cnt;
return 0 ;
}