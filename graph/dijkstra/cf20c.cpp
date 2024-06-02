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



 struct pp{
    int first,second;
 };
 
vector<pp> adj[100006];
int vis[100006];
ll dist[100006];
int parent[100006];
bool operator<(const pp&a,const pp&b){
    return a.first>b.first;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// #ifndef ONLINE_JUDGE 
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif



int t=1;
// cin>>t;
while(t--){ 

int n;
cin>>n;
for(int i=1;i<=n;i++)
{dist[i]=1e15;parent[i]=i;}
int m;
cin>>m;
fi(1,m+1){
    int u,v,w;
    cin>>u>>v>>w;
    pp temp;
    temp.first=v;
    temp.second=w;
    adj[u].push_back(temp);
    temp.first=u;
    adj[v].push_back(temp);
}
dist[1]=0;
parent[1]=0;
priority_queue<pp>pq;
pq.push({0,1});
int node;
while(!pq.empty()){
   node=pq.top().second;
    pq.pop();

    for(auto &it:adj[node]){
        if(it.second+dist[node]<dist[it.first]){
            pp temp;
            dist[it.first]=it.second+dist[node];
            temp.first=it.second+dist[node];
            temp.second=it.first;
            parent[it.first]=node;
            pq.push(temp);
        }
    }
}
if(dist[n]==1e15) {
    cout<<-1<<endl;
    return 0;
}
vector<int>temp;
while(n!=1){
    temp.push_back(n);
    n=parent[n];
}
temp.push_back(1);
reverse(temp.begin(),temp.end());
for(auto i:temp) cout<<i<<" ";cout<<endl;

}
return 0 ;
}