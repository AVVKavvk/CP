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

int sieve[100005];
void createSieve(){
    int n=100000;
 for(int i=2;i<=n;i++) sieve[i]=1;

 for(int i=2;i*i<=n;i++){
    if(sieve[i]==1){
        for(int j=i*i;j<=n;j+=i){
            sieve[j]=0;
        }
    }
 }
}
 
void segementedSieve(){

    createSieve();   // step 1

    int l,r;
    cin>>l>>r;

    vector<int>primes;
                               // step 2 collect  primes number before sqrt(r)
    for(int i=2;i*i<=r;i++){
        if(sieve[i]==1) primes.pb(i);
    }
    
    int dummy[r-l+1];       // step 3  create dummy arrry of size r-l
    for(int i=0;i<r-l+1;i++) dummy[i]=1;
    
    for(auto pr:primes){            // mark primes mul as false

        int firstMultiple= (l/pr) *pr;
        if(l%pr!=0) firstMultiple+=pr;

        for(int j=max(firstMultiple, pr*pr);j<=r;j+=pr){
            dummy[j-l]=0;   // 0 based indexing
        }
    }

    int cnt=0;
    vector<int>ans;

    for(int i=l;i<=r;i++){
        if(dummy[i-l]==1) {
            ans.pb(i);
            cnt++;
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n count is : "<<cnt;

}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

segementedSieve();


return 0 ;
}