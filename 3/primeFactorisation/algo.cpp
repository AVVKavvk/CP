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

  //!    lets n=36   we have start with small  number and end with large number so it will be easy to find the answer
  //!   36 -2-> 18 -2-> 9 -3-> 3 -3->  1       so we choose minimum of that 
                                    // 2|36
                                    // 2|18
                                    // 3|9
                                    // 3|3
                                    // 1|1
 
  
 int sieve[1000006];
 void createSieve(){
    int N=1000001;
    for(int i=2;i<=N;i++) sieve[i]=i;        


    for(int i=2;i*i<=N;i++){           
        if(sieve[i]==i){
            for(int j=i*i;j<=N;j=j+i){
                sieve[j]=min(sieve[j],i);
                // sieve[j]=i;
            }
        }

    }
 }

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


int t=1;
// cin>>t;

createSieve();
while(t--){               // *     TC   ->  t
    int n;
    cin>>n;

    while(sieve[n]!=n){             // *   TC   ->  log n
        cout<<sieve[n]<<" ";
        n=n/sieve[n];

    }
    cout<<n<<endl;


    //  M - 2
    // while(1!=n){             // *   TC   ->  log n
    //     cout<<sieve[n]<<" ";
    //     n=n/sieve[n];

    // }
    
}

                                 //*    TC   ->   tlogn
return 0 ;
}