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
 

 void maxPeak(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    int peak=0;
    int index=0;
    int maxi=0;
    for(int i=1;i<k-1;i++){
        if(arr[i]>arr[i+1] && arr[i]>arr[i-1]) {
            peak++;
        }
    }
    // if(peak>0) {
    //     maxi=peak;
    //     index=0;
    // }
    maxi=peak;
    index=0;
    int l=0;
    int r=k-1;

    while(r<n-1){

        if(arr[r]>arr[r+1] && arr[r]>arr[r-1]) {
            peak++;
        }
        r++;
        l++;
        if(arr[l]>arr[l+1] && arr[l]>arr[l-1]) peak--;
        if(peak>maxi){
            maxi=peak;
            index=l;
        }
    }

    cout<<maxi+1 <<" "<<index+1<<endl;
 }

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
                                     // ?    1341B CF 


int t=1;
cin>>t;
while(t--){ 
maxPeak();

}
return 0 ;
}