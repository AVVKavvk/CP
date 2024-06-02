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

int seg[4*1000005];
int arr[1000005];

void build(int ind,int low,int high){
    if(low==high){
        seg[ind]=arr[low];
        return ;
    }
    int leftIndex=2*ind+1;
    int rightIndex=2*ind+2;
    int mid=low +(high-low)/2;

    build(leftIndex,low,mid);
    build(rightIndex,mid+1,high);
    seg[ind]= seg[leftIndex]+ seg[rightIndex];
}
 
 void update(int ind,int low,int high,int i,int val){
    if(low==high){
        arr[i]+=val;
        seg[ind]+= val;
        return ;
    }
    int mid=low +(high-low)/2;

    

    if(i<=mid){
        update(2*ind+1,low,mid,i,val);
    }
    else {
        update(2*ind+2,mid+1,high,i,val);
    }
    seg[ind]= seg[2*ind+1] + seg[2*ind+2];
 }

 int sumRange(int ind,int low,int high,int l,int r){
    // complete overlapping
    if(low>=l && high<=r) return seg[ind];
    // no overlapping
    if(l>high ||  r<low) return 0;
    
    int mid = low +(high-low)/2;
    int left=sumRange(2*ind+1,low,mid,l,r);
    int right=sumRange(2*ind+2,mid+1,high,l,r);
    return left+right;
 }



int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;

fli(0,n) cin>>arr[i];
build(0,0,n-1);

// update(0,0,n-1,1,4);

// fli(0,4*n) ps(seg[i]);

int q;
cin>>q;
while(q--){
    int type;
    cin>>type;
    if(type==1){
        int i,val;
        cin>>i>>val;
        int temp=val-arr[i];
        arr[i]=val;
        update(0,0,n-1,i,temp);
    }
    else{
        int l,r;
        cin>>l>>r;
        cout<<sumRange(0,0,n-1,l,r)<<endl;
    }
}


return 0 ;
}

// 5
// 2 1 3 4 3