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