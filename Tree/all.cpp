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
 

 int n;
 int height=0;
 vector<int> adj[100005];
 int level[100005];
 int parent[100005];
 int subtree[100005];

 void dfs(int node,int par,int lel=0){
    height=max(height,lel);
    level[node]=lel;
    parent[node]=par;
    int child=0;
    for(auto it:adj[node]){
        if(it!=par){
            dfs(it,node,lel+1);
            child+=subtree[it];
        }
    }
    subtree[node]=1+child;
 }



int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
#ifndef ONLINE_JUDGE 
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

int t=1;
// cin>>t;
while(t--){ 
cin>>n;


for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

dfs(1,0);



// 9
// 1 2
// 1 3
// 1 4
// 3 5
// 3 6
// 6 7
// 6 8
// 6 9






// int node;
// cin>>node;
// // int par=parent[node];
// vector<int>temp;
// while(node!=parent[node]){
//     temp.push_back(node);
//     node=parent[node];
// }
// // temp.push_back(node);
// reverse(temp.begin(),temp.end());
// for(auto i:temp) cout<<i<<" ";cout<<endl;
// for(int i=1;i<=n;i++) {cout<<i<<" -> " <<subtree[i];cout<<endl;}
// nl;nl;
// for(int i=1;i<=n;i++) {cout<<i<<" -> "<<level[i];cout<<endl;}

}
return 0 ;
}