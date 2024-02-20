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


 int parent[100005];
 int Parentsize[100005];

 int findParent(int node){
    if(parent[node]==node) return node;
    else return parent[node]=findParent(parent[node]);
 }

 void unionBySize (int u,int v){
    int upU=findParent(u);
    int upV=findParent(v);
    // cout<<"before"<<u<<" "<<v<<endl;
    if(upU==upV) return ;
    // cout<<"after"<<u<<" "<<v<<endl;
    // cout<<u<<" "<<v<<endl;
    // parent[upU]=parent[upV];
    if(Parentsize[upU]>=Parentsize[upV]){
        parent[upV]=upU;
        Parentsize[upU]+=Parentsize[upV];
    }
    else{
        parent[upU]=upV;
        Parentsize[upV]+=Parentsize[upU];
    }
 }
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,m;
cin>>n;

fli(1,n+1) {
    parent[i]=i;
    Parentsize[i]=1;
    
}
vector<pair<int,int>>old;
fli(0,n-1){
    int u,v;
    cin>>u>>v;
    if(findParent(u)==findParent(v)){
        old.pb({u,v});
    }
    else unionBySize(u,v);
}

set<int> s;
for(int i=1;i<=n;i++){
    s.insert(findParent(i));
}

int cnt=s.size()-1;
cout<<cnt<<endl;

vector<int> cmponents(s.begin(),s.end());
for(int i=0;i<cnt;i++){
    cout<<old[i].first<<" "<<old[i].second<<" "<<cmponents[i]<<" "<<cmponents[i+1]<<endl;
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