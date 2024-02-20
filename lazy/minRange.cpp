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

ll seg[4*1000005];
ll lazy[4*1000005];
ll arr[1000005];

void build(int ind,int low,int high){
    if(low==high){
        seg[ind] = arr[low];
        return ;
    }
    int mid= low+(high-low)/2;
    build(2*ind+1 , low , mid );
    build(2*ind+2,mid+1,high);
    seg[ind]= min(seg[2*ind+1],seg[2*ind+2]);
}
 

 void update(int ind,int low,int high,int l,int r,int val){

    if(lazy[ind]!=0){
        seg[ind]+=lazy[ind];
        if(low != high){
            lazy[2*ind +1 ]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }
        lazy[ind]=0;
    }

    // no overlap    l r low high   low high l r
    if(low>r || l>high) return ;
    // complete overlap      l low high r

    if(low>=l && high<=r){
        seg[ind]+=val;
        if(low != high ){
            lazy[2*ind+1 ]+=val;
            lazy[2*ind+2]+=val;
        }
        return ;


    }
    int mid= low+(high-low)/2;
    update(2*ind+1,low,mid,l,r,val);
    update(2*ind+2,mid+1,high,l,r,val);

    seg[ind]=min(seg[2*ind+1] , seg[2*ind+2]) ;
 }
  
  ll minRange(int ind,int low,int high,int l,int r){

    if(lazy[ind]!=0){
        seg[ind]+= lazy[ind];

        if(low!=high){
            lazy[2*ind+1] +=lazy [ind];
            lazy[2*ind+2]+=lazy[ind];
        }

        lazy[ind]=0;
    }
    
    // no overlap

    if(low>r ||  high < l) return INT_MAX;

    // complete overlap

    if(low>=l && high<=r) return seg[ind];

    int mid=low+(high-low)/2;

    ll left=minRange(2*ind+1,low,mid,l,r);
    ll right= minRange(2*ind+2,mid+1,high,l,r);
    return  min(left,right);


  }
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;
fli(0,n) cin>>arr[i];
build(0,0,n-1);
int m;
cin>>m;
cin.ignore();
while (m--) {
    string str;
    getline(cin,str);
    ll var;
    stringstream ss(str);
    vector<ll>tmp;
    while(ss>>var){
        tmp.pb(var);
    }
    if(tmp.size()==2){
  
      ll l=tmp[0];
      ll r=tmp[1];

      if(l>r){
        ll min1=minRange(0,0,n-1,l,n-1);
        ll min2=minRange(0,0,n-1,0,r);
        cout<<min(min1,min2)<<endl;
      }
      else {
        cout<<minRange(0,0,n-1,l,r)<<endl;
      }
      
    }
    else if(tmp.size()==3){
           ll l=tmp[0];
           ll r=tmp[1];
           ll val=tmp[2];
        //    update(0,0,n-1,l,r,val);
        if(l>r){
            update(0,0,n-1,l,n-1,val);
            update(0,0,n-1,0,r,val);
        }
        else {
            update(0,0,n-1,l,r,val);
        }
    }
}

return 0 ;
}