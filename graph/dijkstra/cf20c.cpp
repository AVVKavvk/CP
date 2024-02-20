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

// int n;
struct pp
{
    int first, second;
};
 
bool operator<(const pp &a, const pp &b){
// {   cout<<a.second<<"  "<<b.second<<endl;
    return a.second > b.second;
}
vector< pp > adj[100005];
int vis[100005];
ll dist[100005];
int parent[100005];
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
int m;
cin>>n>>m;

while(m--){
    int u,v,w;
    cin>>u>>v>>w;
    pp temp;
            temp.first=v;
            temp.second=w;
    adj[u].pb(temp);
  temp.first=u;
            temp.second=w;
    adj[v].pb(temp);

}


for(int i=1;i<=n;i++) parent[i]=i;
for(int i=1;i<=n;i++) dist[i]=1e15;
dist[1]=0;

    
    
    priority_queue<pp> pq;
    pq.push({1,1});
    pq.push({1,0});
    pq.push({1,-1});

    auto first=pq.top();
    
    int a;
    while(!pq.empty())
    {
        a=pq.top().first;
        pq.pop();
        for(const auto &x: adj[a])
        {
            if(dist[x.first]>dist[a]+x.second)
            {
                dist[x.first]=dist[a]+x.second;
                pp temp;
            temp.first=x.first;
            temp.second=dist[x.first];
                pq.push(temp);
                parent[x.first]=a;
            }
        }
    }

if(dist[n]==1e15) {cout<<-1<<endl;return 0;}
vector<int> ans;
int node=n;
while(node!=1){
    
    ans.push_back(node);
    node=parent[node];
}
ans.push_back(1);
reverse(ans.begin(),ans.end());
for(auto i:ans){
    cout<<i<<" ";
}
cout<<endl;

return 0 ;
}