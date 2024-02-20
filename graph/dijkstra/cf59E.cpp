// https://codeforces.com/contest/59/problem/E
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


 struct node{
    int prev,curr,next;
    node(){
        prev=curr=next=0;
    }
 };

 struct pp{
    int dis,node,prev;
    pp(){
        dis = node = prev = 0;
    }
 };

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


int n,m,k;
cin >> n>> m>> k;
vector<int> adj[n+1];
fli(0,m){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].pb(u);
}
set<pair<int,pair<int,int>>>s;
while(k--){
//    cout<<"vipin \n";
    int prev,curr,next;
    cin>>prev>>curr>>next;
    s.insert({prev,{curr,next}});
}

int dist[n+1][n+1];
fli(1,n+1){
    flj(1,n+1){
        dist[i][j]=1e9;
    }
}

dist[1][1]=0;

queue <pair<int,pair<int,int>> > q;
// pp tmp;
// tmp.dis=0;
// tmp.node=1;
// tmp.prev=1;
// q.push(tmp);
q.push({0, {1, 1}});

int lastnode,lastdist;
while(!q.empty()){
    auto it=q.front();
    q.pop();
    int dis=it.first;
    int node=it.second.first;
    int prev=it.second.second;
    if(node==n){
        dist[n][n]=lastdist;
        lastnode=prev;
        lastdist=dis;
        break;
    }
   pair<int,pair<int,int>>tmp;
   tmp.first=prev;
   tmp.second.first=node;
    


    for(auto itr:adj[node]){
        // if(itr==prev) {continue;}
        tmp.second.second=itr;
        if(s.find(tmp)!=s.end()) continue;

        if(dis +1 < dist[itr][node]){
            dist[itr][node] = dis + 1;
            q.push({dis+1, {itr, node}});
        }

    }
}

if(dist[n][n]==1e9) {
    cout<<-1<<endl;
    return 0;
}
cout<<lastdist<<endl;
vector<int> ans;
ans.pb(n);
while(lastdist!=0){
    lastdist--;
    
    ans.pb(lastnode);
    for(int i=1;i<=n;i++){
        if(dist[lastnode][i]==lastdist){
            lastnode=i;
            break;
        }

    }
}
reverse(ans.begin(),ans.end());
for(auto x : ans)cout<<x<<" ";
cout<<endl;

return 0 ;
}