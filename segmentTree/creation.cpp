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

int arr[1000005];
int seg[4*1000005];


int minRange(int ind,int low,int high,int l,int r){
    
    // complete overlapping
    if(low>=l && high<=r) return seg[ind];
    
    // no  overlapping
   
    if(l>high || low>r) return INT_MAX;

    int leftIndex=2*ind+1;
    int rightIndex=2*ind+2;
    int mid=low+ (high-low)/2;

    int left=minRange(leftIndex,low,mid,l,r);
    int right=minRange(rightIndex,mid+1,high,l,r);
    return  min(left,right);
 
}
void update(int ind,int low,int high,int i,int val){
    if(low==high){
        seg[ind]=val;
        arr[i]=val;
        return ;
    }
    int mid=low+(high-low)/2;

    if(i<=mid){
        update(2*ind +1 ,low , mid ,i ,val);
    }
    else {
        update(2*ind+2,mid+1,high,i,val);
    }

    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    
}
void build(int ind,int low,int high){
    if(low==high){
        seg[ind] = arr[low];
        return ;
    }
    int leftIndex=2*ind+1;
    int rightIndex=2*ind+2;
    int mid=low+(high-low)/2;
    build(leftIndex , low , mid );
    build(rightIndex,mid+1,high);
    seg[ind]=min(seg[leftIndex],seg[rightIndex]);
}
 


int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;
for(int i=0;i<n;i++) cin>>arr[i];
build(0,0,n-1);


// pn(minRange(0,0,n-1,1,5));
// cout<<minRange(0,0,n-1,1,5);
int q;
cin>>q;
while(q--){
    int l,r;
    cin>>l>>r;
    pn(minRange(0,0,n-1,l,r));
}
// for(int i=0;i<13;i++){
//     ps(seg[i]);
// }

return 0 ;
}

// 7
// 1 2 0 4 0 1 5