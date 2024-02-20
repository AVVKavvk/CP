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



int lel[1000005];
int parent[1000005][18];
vector<int> adj[1000005];

void dfs(int node,int par,int level=1){
    parent[node][0]=par;
    for(int i=1;i<18;i++){
        parent[node][i]= parent[parent[node][i-1]][i-1];

    }
    lel[node]=level;
    for(auto it:adj[node]){
        if(it!=par){
            dfs(it,node,level+1);
        }
    }
}

int lca(int u,int v){
    if(lel[v]>lel[u] ) swap(u,v);
    int k=lel[u]-lel[v];
    int cnt=0;
    while(k){
        if(k&1) u=parent[u][cnt];
        cnt++;
        k=k>>1;
    }
    if(u==v) return u;

    for(int i=17;i>=0;i--){
        if(parent[u][i]!=parent[v][i]){
            u=parent[u][i];
            v=parent[v][i];
        }
    }

    return parent[u][0];

}


int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


int n,q;
cin>>n>>q;
int index=2;
for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    
}

dfs(1,0);

while(q--){
   int u,v;
   cin>>u>>v;
   int nodeLca=lca(u,v);
   int y=abs(lel[nodeLca]-lel[u]);
   int x=abs(lel[nodeLca]-lel[v]);
   long long ans=x+y;
   cout<<ans<<endl;
} 




return 0 ;
}