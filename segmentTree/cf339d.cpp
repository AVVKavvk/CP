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
int n;
void build(int ind,int low,int high,int flag){
      if(low==high){
        seg[ind] = arr[low];
        return ;
      }
      int mid =low +(high-low)/2;

      build(2*ind , low , mid ,!flag); 
      build(2*ind+1 , mid+1 , high ,!flag) ;
      
      if(n%2){
        if(flag%2){
            seg[ind]=seg[2*ind]| seg[2*ind+1];
        }
        else{
            seg[ind]=seg[2*ind]^seg[2*ind+1];
            }
 
      }
      else{
         if(flag%2){
            seg[ind]=seg[2*ind]^seg[2*ind+1];
         }
         else {
            seg[ind]=seg[2*ind]|seg[2*ind+1];
         }
      }

}
 
 void update(int ind,int low,int high,int flag,int i,int val){
     if(low==high){
        seg[ind] = val;
        arr[i]=val;
        // cout<<ind<<"-> "<<seg[ind]<<"\n";
        return ;
      }
      int mid =low +(high-low)/2;
      if(i<=mid)
      update(2*ind , low , mid ,!flag,i,val); 
      else
      update(2*ind+1 , mid+1 , high ,!flag,i,val) ;


      
      if(n%2){
        if(flag%2){
            seg[ind]=seg[2*ind]| seg[2*ind+1];
        }
        else{
            seg[ind]=seg[2*ind]^seg[2*ind+1];
            }
 
      }
      else{
         if(flag%2){
            seg[ind]=seg[2*ind]^seg[2*ind+1];
         }
         else {
            seg[ind]=seg[2*ind]|seg[2*ind+1];
         }
      }
 }

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int q;
cin>>n>>q;
int el=1<<n;
fli(1,el+1) cin>>arr[i];
build(1,1,el,1);


// fli(1,el+1) cout<<seg[i]<<" ";
while(q--){
    int i,val;
    cin>>i>>val;
    // i--;
    update(1,1,el,1,i,val);
    cout<<seg[1]<<endl;
}

// fli(1,el+1) cout<<seg[i]<<" ";

return 0 ;
}

// 2 4
// 1 2 3 4