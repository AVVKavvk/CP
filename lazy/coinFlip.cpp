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
bool lazy[4*1000005];
int arr[1000005];

void build(int ind,int low,int high){
    if(low == high){
        seg[ind]=arr[low];
        return ;
    }
    int mid =low+ (high-low ) / 2 ;
    build(2 * ind + 1 , low , mid );
    build(2*ind+2,mid+1,high);
    seg[ind]=seg[2*ind+1] + seg[2*ind+2];
}
 
 void update(int ind,int low,int high,int l,int r,int val){

    if(lazy[ind]){
        seg[ind]=(high - low + 1)-seg[ind];

        if(low!=high){
            lazy[2*ind+1] =!lazy[2*ind+1];
            lazy[2+ind+2]=!lazy[2*ind+2];
        }
        lazy[ind]=0;
    }

    // no overlap     l r low high      low high l r


    if(high<l || low>r) return ;

    // complete overlap
   // l low high r
    if(low>=l && high<=r){
        seg[ind]=(high - low + 1)-seg[ind];
        if(low != high ){
            lazy[2*ind+1 ]=!lazy[2*ind+1 ];
            lazy[2*ind+2]=!lazy[2*ind+2 ];
        }
        return ;
    }

    int mid= low+(high-low)/2;
    update(2*ind+1,low,mid,l,r,val);
    update(2*ind+2,mid+1,high,l,r,val);

    seg[ind]=seg[2*ind+1] + seg[2*ind+2];

 }

  int sumRange(int ind,int low,int high,int l,int r){

    if(lazy[ind]){
        seg[ind]= (high-low+1)-seg[ind];

        if(low!=high){
            lazy[2*ind+1] =!lazy[2*ind+1];
            lazy[2*ind+2]=!lazy[2*ind+2];
        }

        lazy[ind]=0;
    }
    
    // no overlap

    if(low>r ||  high < l) return 0;

    // complete overlap

    if(low>=l && high<=r) return seg[ind];

    int mid=low+(high-low)/2;

    int left=sumRange(2*ind+1,low,mid,l,r);
    int right= sumRange(2*ind+2,mid+1,high,l,r);
    return  left+right;


  }

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;
fli(0,n) cin>>arr[i];
build(0,0,n-1);
int q;
cin>>q;
cin.ignore();
while(q--){
    string s;
    vector<int>tmp;
    getline(cin,s);
    stringstream ss(s);
    int var;
    while(ss>>var){
        tmp.push_back(var);
    }
    if(tmp.size()==2){
        int l=tmp[0];
        int r=tmp[1];
        cout<<sumRange(0,0,n-1,l,r)<<endl;
    }
    else if(tmp.size()==3){
          int l=tmp[0];
          int r=tmp[1];
          int flip=tmp[2];
          update(0,0,n-1,l,r,flip);

        //   fli(0,n) cout<<"update "<<arr[i]<<" ";
        //   cout<<endl;
    }

}

return 0 ;
}