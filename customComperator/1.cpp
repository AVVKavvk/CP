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


ll bTD(){ string s;cin>>s;ll num=0;
for(auto ch:s){if(ch=='1')num = num*2 + 1;else num=num*2;}
return num;}; 
bool pOf2(ll num){if(num<=0) return false;if((num&(num-1))==0) return true;else return false;}
 
struct ppp{
    int first,second,third;

};

//  struct cmp{ 
//  bool operator()(const ppp&a,const ppp&b){       // ?   sort
//     if(a.third!=b.third){
//         return a.third > b.third;
//     }
//     return a.second < b.second;
//  }
//  };


 struct cmp{
 bool operator()(const ppp&a,const ppp&b){
    if(a.third!=b.third){                         //? PQ
        return a.third < b.third;
    }
    return a.second > b.second;
 }
 };

//  bool cmp(const ppp&a,const ppp&b){
//     if(a.third!=b.third){
//         return a.third > b.third;
//     }
//     return a.second > b.second;
//  }
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

priority_queue< ppp , vector<ppp>,cmp > pq;
int n;
cin>>n;
int w=n;
while(w--){
    int u,v,w;
    cin>>u>>v>>w;
    ppp tt;
    tt.first=u;
    tt.second=v;
    tt.third=w;
    pq.push(tt);

}

// sort(temp.begin(),temp.end(),cmp());
cout<<endl<<endl;
while(!pq.empty()){
    auto it=pq.top();
    pq.pop();
    cout<<it.first<<" "<<it.second<<" "<<it.third<<endl;
}
// while(w--){
//     int u,v,w;
//     cin>>u>>v>>w;
//     ppp tt;
//     tt.first=u;
//     tt.second=v;
//     tt.third=w;
//     temp.push_back(tt);

// }

// sort(temp.begin(),temp.end(),cmp());
// cout<<endl<<endl;
// fi(0,n){
//     auto it=temp[i];
//     cout<<it.first<<" "<<it.second<<" "<<it.third<<endl;
// }

}
return 0 ;
}