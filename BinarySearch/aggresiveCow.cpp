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
 bool isPossible(int arr[],int cow,int mid,int n){
    int last=arr[0];
    int c=1;

    for(int i=1;i<n;i++){
        if((arr[i]-last)>=mid){
            c++;
            last=arr[i];
        }
        if(c==cow) return true;
    }
    return c<=cow;
 }
void aggresiveCow(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int cow;
    cin>>cow;
    sort(a,a+n);
    int low=1;
    int high=a[n-1];
    
    int ans=1;
    while(low<=high){
        int mid=low+(high-low)/2;

        if(isPossible(a,cow,mid,n)){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    cout<< ans;
}
 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// #ifndef ONLINE_JUDGE 
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif



int t=1;
cin>>t;
while(t--){ 


}
return 0 ;
}