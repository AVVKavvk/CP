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


 ll Euler(int n){
    ll ans=1;

    for(int i=2;i*i<=n;i++){        // *     sqrt(n)*logn

        int cnt=0;
        while(n%i==0){
            cnt++;
            n=n/i;
        }
        
        if(cnt!=0)
        ans=ans*(pow(i,cnt)-pow(i,cnt-1));
    }
    if(n>=2) ans=ans*(n-1);                        // ? 
    return ans;
 }

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;

cout<<Euler(n)<<endl;

return 0 ;
}