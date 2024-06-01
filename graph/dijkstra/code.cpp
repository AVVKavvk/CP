#include<bits/stdc++.h>
using namespace std ; 
#define ll long long
#define limit(x) (x.begin(),x.end())


 int dist[1000006];

void dijkstra(int node,vector<pair<int,int>> adj){
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,node});

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=pq.second;
        int dis=pq.first;

        for(auto adjNode:adj[node]){
            int v=adjNode.first;
            int w=adjNode.second;

            if(dis + w <dist[v]){
                dist[v]=dis+w;
                pq.push(dist[v],v);
            }
        }
    }
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


int n;
int m;
cin>>n>>m;

vector<pair<int,int>> adj[n+1];

for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;

    adj[u].pb({v,w});
    adj[v].pb({u,w});
}
memset(dist , 1e8, sizeof(dist));
dist[1]=0;
dijkstra(1,adj);
return 0 ;
}