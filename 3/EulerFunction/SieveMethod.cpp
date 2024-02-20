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

//!   using  technique of primefactorisation  algo

 ll sieve[1000006];
void EulerSieve(){
   int N=1000000;
   for(int i=2;i<=N;i++){        //*    n
    sieve[i]=i;
   }

   for(int i=2;i*i<=N;i++){        //* sqrt(n)
    if(sieve[i]==i){

        for(int j=i*i;j<=N;j+=i){
            sieve[j]=min(sieve[j],1ll*i);
        }
    }
   }
   

}
 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;

   EulerSieve();

   double ans=n;
   unordered_set<int>st;       //* log(n)  max log n element

   while(sieve[n]!=n){    //*  logn * 1 
    st.insert(sieve[n]);  // *   if map  then   logn * loglogn
    n=n/sieve[n];
   }
   st.insert(n);

   for(auto it:st){
    ans=ans*(1.0-1.0/it);
   }

   cout<< ans;


return 0 ;
}