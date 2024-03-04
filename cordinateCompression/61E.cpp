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

int n;

 
ll fenLeft[1000005];
ll fenRight[1000005];

ll sumLeft(int index){
    ll sum=0;

    while(index>0){
        sum+=fenLeft[index];
        index-=index & (-index);
    }

    return sum;
} 
ll sumRight(int index){
    ll sum=0;

    while(index>0){
        sum+=fenRight[index];
        index-=index & (-index);
    }

    return sum;
} 

void updateLeft(int index,int val){

    while(index<=n){
        fenLeft[index]+=val;
        index+=index & (-index);
    }
}

void updateRight(int index,int val){

    while(index<=n){
        fenRight[index]+=val;
        index+=index & (-index);
    }
}

void cordinateCompression(ll arr[]){
    set<ll>s;
    for(int i=1;i<=n;i++){
        s.insert(arr[i]);
    }
    int cnt=1;
    
    map<ll,int>mp;
    for(auto it:s){
        mp[it]=cnt++;
    }
    for(int i=1;i<=n;i++){
        arr[i]=mp[arr[i]];
    }
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

cin>>n;

ll arr[n+1];
for(int i=1;i<=n;i++) cin>>arr[i];
cordinateCompression(arr);

for(int i=1;i<=n;i++) updateRight(arr[i],1);

ll triplet=0;

for(int i=1;i<=n;i++){
    
    updateRight(arr[i],-1);

    updateLeft(arr[i],1);

    ll left=sumLeft(n)-sumLeft(arr[i]);
    ll right=sumRight(arr[i]-1);
    triplet+=left*right;

}
cout<<triplet<<endl;
return 0 ;
}