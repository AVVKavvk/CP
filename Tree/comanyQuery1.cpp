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

// vector<int> adj[1000005];

// int parent[1000005];
// int lel[1000005];

// void dfs(int node,int par,int level=1){
//     parent[node]=par;
//     lel[node]=level;

//     for(auto it:adj[node]){
//         if(it!=par){
//             dfs(it,node,level+1);
//         }
//     }
// }



int parent[1000005][18];
vector<int> adj[1000005];

void dfs(int node,int par,int level=1){
    parent[node][0]=par;
    for(int i=1;i<18;i++){
        parent[node][i]= parent[parent[node][i-1]][i-1];

    }

    for(auto it:adj[node]){
        if(it!=par){
            dfs(it,node,level+1);
        }
    }
}



int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


int n,q;
cin>>n>>q;
int index=2;
for(int i=0;i<n-1;i++){
    int u;
    cin>>u;
    adj[u].push_back(index);
    adj[index].push_back(u);
    index++;
}

dfs(1,0);

while(q--){
    int cnt=0;
    int node,k;
    cin>>node>>k;
    while(k){
        if(k&1){
            node=parent[node][cnt];
        }
        cnt++;
        k=k>>1;
    }
    if(node==0) cout<<-1<<endl;
    else
    cout<<node<<endl;
}




// int n,q;
// cin >> n>> q;
// for(int i=2;i<=n;i++){
//    int v;
//    cin>>v;
//    adj[v].push_back(i);
// }

// dfs(1,0);

// while(q--){
//     int ans=-1;
//     int node,k;
//     cin>>node>>k;

//     while(node!=1){
//         if(k==0) {
//             ans=node;
//             break;
//         }
//         k--;
//         node=parent[node];
//     }
//     if(k==0 && ans==-1){
//         cout<<1<<endl;
//     }
//     else cout<<ans<<endl;
// }



return 0 ;
}