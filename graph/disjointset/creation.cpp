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
    if(node==parent[node]) return node;
    return parent[node] = findParent(parent[node]);
 }

 void unionBySize(int u,int v){
    int up_u=findParent(u);
    int up_v=findParent(v);
    if(up_u==up_v) return ;
    if(size[up_u]>=size[up_v]){
        size[up_u]+=size[up_v];
        parent[up_v]=up_u;
    }
    else {
        size[up_v]+=size[up_u];
        parent[up_u]=up_v;
    }
 }

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

for(int i=0;i<1000006;i++){ parent[i]=i;size[i]=1;}

 


return 0 ;
}