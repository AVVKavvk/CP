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

 vector<int> adj[26];
int vis[26]={0};
int topoVis[26]={0};
 vector<int> pathVis(26,0);

 stack<char>st;

bool checkIsCycle(int node){
    vis[node]=pathVis[node]=1;

    for(auto it:adj[node]){
        if(vis[it]==0){
           if(checkIsCycle(it)==true) return true;
        }
        else if(1==pathVis[it]){return true;}
    }
    pathVis[node]=0;
    return false;
}

void topoSort(int node){
    // cout<<node;
    topoVis[node]=1;
    for(auto it:adj[node]){
        if(!topoVis[it]){
        topoSort(it);
        }
    }
    st.push(node+'a');
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;

string arr[n];
for(int i=0;i<n;i++) cin>>arr[i];

for(int i=0;i<n-1;i++){
    string s1=arr[i];
    string s2=arr[i+1];
    
    for(int j=0;j<s1.size();j++){
        if(j>=s2.size()){
            
            cout<<"Impossible"<<endl;
            return 0;
        }
        else{
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                // cout<<s1[j]<<" "<<s2[j]<<endl;
                break;
            }

        }
    }
  
}


for(int i=0;i<26;i++){
    if(!vis[i]){
        if(checkIsCycle(i)==true){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
}


// for(int i=0;i<26;i++){
//     for(auto it:adj[i]){
//         cout<<char(i+'a')<<"->" <<char(it+'a')<<" ";
//     }
//     cout<<endl;
// }

memset(vis , 0, 26);
for(int i=0;i<26;i++){
    if(!topoVis[i]){
        
        topoSort(i);
    }
     
}

while(!st.empty()){
    cout<<st.top();
    st.pop();
}
cout<<endl;
return 0 ;
}