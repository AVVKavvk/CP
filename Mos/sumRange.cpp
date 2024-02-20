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
int sqrt_el;



 bool cmp(pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b){
    int blockNo1=a.first.first/sqrt_el;
    int blockNo2=b.first.first/sqrt_el;

    if(blockNo1<blockNo2) return true;
    if(blockNo1==blockNo2){
        if(a.first.second<=b.first.second) return true;
    }
    return false;
 }



int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;
fli(0,n){
    cin>>arr[i];
}

sqrt_el=sqrt(n);

vector<pair<pair<int,int>,int>>qureies;

int q;
cin>>q;
for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    qureies.pb({{l,r},i});
}

sort(qureies.begin(),qureies.end() ,cmp);

int ans[q];

int left=0;
int right=0; 
ll sum=arr[0];                                // todo  
for(auto it:qureies){
      int l=it.first.first;
      int r=it.first.second;
      int ind=it.second;
      
      while(left<=l){                         // ?   striver mistake
        sum-=arr[left];
        left++;

      }
      while(left>l){
        left--;
        sum+=arr[left];
      }

      while(right<=r){
        right++;
        sum+=arr[right];
      }
      while(right>r){
        sum-=arr[right];
        right--;
      }

      ans[ind]=sum;
}

for(auto it:ans){
    cout<<it<<endl;
}

return 0 ;
}



// 5 
// 3 1 5 2 6
// 4
// 1 4
// 0 2
// 1 3
// 0 4