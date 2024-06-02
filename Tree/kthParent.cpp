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
 
int parent[1000006][18];
int level[1000006];
int subtree[1000006];
int n;

vector<int> adj[1000006];
 
 void dfs(int node,int par,int lel=0){
    parent[node][0]=par;
    for(int i=1;i<18;i++){
        parent[node][i]=parent[parent[node][i-1]][i-1];
    }
    level[node]=lel;
    int child=0;
    for(auto it:adj[node]){
        if(it!=par){
            dfs(it,node,lel+1);
            child+=subtree[it];
        }
    }
    subtree[node]=1+child;
 }

void kthParent(){
    int node;
    cin>>node;
    int k;
    cin>>k;
    int cnt=0;

    while(k>0){
        if(k&1) node=parent[node][cnt];
        k=k>>1;
        cnt++;
    }
    cout<<node<<endl;
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
fi(1,n){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

dfs(1,0);

kthParent();

}
return 0 ;
}



