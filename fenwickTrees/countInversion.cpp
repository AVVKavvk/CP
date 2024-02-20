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
 
long long fen[10000005];
// int freq[1000005];

void update(long long index,int val){
        // cout<<"vo";
    while(index<=10000005){
        fen[index] +=val;
        index+= (index&-index);
    }
}

long long sum(long long index){
    long long res=0;
    while(index>0){
        res+=fen[index];
        index-=(index&-index);
    }
    return res;
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
    memset(fen,0,sizeof (fen));
   
    long long n;
    cin>>n;
    long long arr[n+1];
    for(long long i=1;i<=n;i++){
        cin>>arr[i];

        update(arr[i],1);
    }

    long long cnt=0;
    for(long long i=1;i<=n;i++){
        

        update(arr[i],-1);
       
        cnt+=sum(arr[i]-1);
    }

cout<<cnt<<endl;
}
return 0 ;
}