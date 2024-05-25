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
#define limit(x) x.begin(),x.end()


ll bTD(){ string s;cin>>s;ll num=0;
for(auto ch:s){if(ch=='1')num = num*2 + 1;else num=num*2;}
return num;}; 
bool pOf2(ll num){if(num<=0) return false;if((num&(num-1))==0) return true;else return false;}
 

 bool isAble(int arr[],int sum,int k,int n){
    int s=0;

    for(int i=0;i<n;i++){
        s+=arr[i]/k;
    }
    if(s<=sum) return 1;
    return 0;
 }
void findKDivide(){
    int n;
    cin>>n;
 
    int arr[n];
    
    for(int i=0;i<n;i++)cin>>arr[i];

    int sum;
    cin>>sum;

   int maxi=1;
   for(int i=0;i<n;i++) maxi=max(maxi,arr[i]);

   int low=1;
   int ans=-1;
   maxi++;
   while(low<=maxi){
    int mid=(low+maxi)/2;
    if(isAble(arr,sum,mid,n)){
        ans=mid;
        maxi=mid-1;
    }
    else low=mid+1;
   }
cout<<ans<<endl;
}
 

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
findKDivide();

}
return 0 ;
}


// 7
// 2 3 5 8 11 13 16
// 10