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


 //!     mul from i=1 to z-1  
                                 //? https://www.hackerearth.com/problem/algorithm/fact-count-a6300182/
//!      i mod z=z-1   

//?       count prime numbers


bool sieve[100000001];

void createSieve(){
	int N=100000000;
     for(int i=2;i<=N;i++){
            sieve[i]=1;
        }
        
        for(int i=2;i*i<=N;i++){
            if(sieve[i]==1){
                for(int j=i*i;j<=N;j=j+i){
                    sieve[j]=0;
                }
            }
        }
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

createSieve();

int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int arr[n];
    fli(0,n) cin>>arr[i];

    int cnt=0;
    for(int i=0;i<n;i++){
        if(sieve[arr[i]]==1) cnt++;
    }
    cout<<cnt<<endl;
}

return 0 ;
}