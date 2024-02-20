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
 
 
 vector<int> adj[1000005];
 int height=0;
 int lel[1000005];
 int parent[1000005];
 
 int subtree[1000005];
 void dfs(int node,int par,int level=1){
    
    height=max(height,level);
    lel[node]=level;
    parent[node]=par;
    int sum=0;
    for(auto it:adj[node]){
        if(it!=par){
            dfs(it,node,level+1);
            sum+=subtree[it];
        }
    }
    subtree[node] =1+sum;
 }

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
int n;
cin>>n; 
for(int i=1;i<n;i++){  // n-1 edges
  int u,v;
  cin>>u>>v;
  adj[u].push_back(v);
  adj[v].push_back(u);
}

dfs(1,0);
// cout<<height;

// for(int i=1;i<=9;i++){
//     cout<<i<<" "<<subtree[i]<<endl;
// }

    // cout<<6<<" "<<subtree[6]<<" " <<lel[6]<<endl;
}

return 0 ;
}


// 1
// 9 
// 1 2
// 1 3
// 1 4
// 3 5
// 3 6
// 6 7
// 6 8
// 6 9