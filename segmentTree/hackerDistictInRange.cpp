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


 int arr[100005];
 int brr[100005];
 
 bitset<5001> seg1[4*100005];
 bitset<5001> seg2[4*100005];

 void build1(int ind,int low,int high){
    if(low==high){
        seg1[ind].set(arr[low]);
        return ;
    }

    int mid= low+(high-low)/2;
    build1(2*ind+1 ,low ,mid );
    build1(2*ind+2,mid+1,high);
    seg1[ind] = seg1[2*ind +1 ] | seg1[2*ind +2];
 }

 bitset<5001> getDistinct1(int ind,int low,int high,int l,int r){
    if(low>=l && high<=r) return seg1[ind];

    if(low> r || l>high) {
        bitset<5001> temp;
        return temp;
    }
    int mid= low+(high-low)/2;
    bitset<5001> left=getDistinct1(ind*2+1,low,mid,l,r);
    bitset<5001> right=getDistinct1(ind*2+2,mid+1,high,l,r);
    return left| right;


 }
 void build2(int ind,int low,int high){
    if(low==high){
        seg2[ind].set(brr[low]);
        return ;
    }

    int mid= low+(high-low)/2;
    build2(2*ind+1 ,low ,mid );
    build2(2*ind+2,mid+1,high);
    seg2[ind] = seg2[2*ind +1 ] | seg2[2*ind +2];
 }

 bitset<5001> getDistinct2(int ind,int low,int high,int l,int r){
    if(low>=l && high<=r) return seg2[ind];

    if(low> r || l>high) {
        bitset<5001> temp;
        return temp;
    }
    int mid= low+(high-low)/2;
    bitset<5001> left=getDistinct2(ind*2+1,low,mid,l,r);
    bitset<5001> right=getDistinct2(ind*2+2,mid+1,high,l,r);
    return left| right;


 }

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


int n;
cin>>n;
fli(0,n) cin>>arr[i];
fli(0,n) cin>>brr[i];
build1(0,0,n-1);
build2(0,0,n-1);
int q;
cin>>q;
while(q--){
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    l1--;
    l2--;
    r1--;
    r2--;
    bitset<5001> left=getDistinct1(0,0,n-1,l1,r1);
    bitset<5001> right=getDistinct2(0,0,n-1,l2,r2);
    bitset<5001> ans=left|right;
    int cnt=ans.count();
   
    cout<<cnt<<endl;



}
return 0 ;
}