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


struct node{
    int open, close,full;
    node(){
        open = 0 , close = 0 , full = 0 ;
    }
};
string s;
node seg[4*1000005];

void build(int ind ,int low,int high){
    if(low==high){
        node temp;
        if(s[low]=='('){
            temp.open=1;
        }
        else {
            temp.close=1;
        }
        seg[ind]=temp;
        return ;

    }
    int mid=low+(high-low)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    node left=seg[2*ind+1];
    node right=seg[2*ind+2];
    node temp;
    temp.full = left.full + right.full + min(left.open,right.close);
    temp.open=left.open + right.open -  min(left.open,right.close);
    temp.close= left.close + right.close -  min(left.open,right.close);

    seg[ind]=temp;
}
 node findLength(int ind,int low,int high,int l,int r){
    // full overlapping
    if(low>=l && r>=high) return seg[ind];
    
    // no overlap
    if(high<l || r<low )return node();

    int mid=low+(high-low)/2;
    node left=findLength(2*ind+1,low,mid,l,r);
    node right=findLength(2*ind+2,mid+1,high,l,r);
    node temp;
    temp.full = left.full + right.full + min(left.open,right.close);
    temp.open=left.open + right.open -  min(left.open,right.close);
    temp.close= left.close + right.close -  min(left.open,right.close);
    return temp;

 }

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>s;

int q;
cin>>q;
build(0,0,s.size()-1);  // ?   learn
while(q--){
int l,r;
cin>>l>>r;
l--;
r--;
node ans=findLength(0,0,s.size()-1,l,r);
cout<<ans.full*2<<"\n";
}

return 0 ;
}