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


 int parent[1000005];
 int size[1000005];

 int findParent(int node){
    if(parent[node]==node) return node;
    else return parent[node]=findParent(parent[node]);
 }

 void unionBySize (int u,int v){
    int upU=findParent(u);
    int upV=findParent(v);
    if(upU==upV) return ;

    if(size[upU]>=size[upV]){
        parent[upV]=upU;
        size[upU]+=size[upV];
    }
    else{
        parent[upU]=upV;
        size[upV]+=size[upU];
    }
 }
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,m;
cin>>n>>m;

fli(1,n+1) {
    parent[i]=i;
    size[i]=1;
}

vector<pair<int,pair<int,int > > > edges;
fli(0,m){
    int u,v,wt;
    cin>>u>>v>>wt;
edges.push_back({wt,{u,v}});
}

sort(edges.begin(),edges.end());

int sum=0;
vector<pair<int,int>>mst;

for(auto it:edges){
    int w = it.first;
    int u=it.second.first;
    int v=it.second.second;

    if(findParent(u)!=findParent(v)){
        unionBySize(u,v);
        sum+=w;
        mst.push_back({u,v});
    }
}

cout<<sum<<endl;
for(auto it:mst){
    cout<<it.first<<" -> "<<it.second<<endl;
}

return 0 ;
}

// 6 9
// 1 4 1
// 1 2 2
// 1 5 4
// 5 4 9
// 2 4 3
// 4 3 5
// 2 3 3
// 2 6 7
// 3 6 8