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


 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


vector<int>arr={1,2,6,4,7,8,5,66,77};
int n=arr.size();
int k;
cin>>k;

priority_queue<int,vector<int>,greater<int>>pq;

for(int i=0;i<k;i++) pq.push(arr[i]);

for(int i=k;i<n;i++){
    if(pq.top()<arr[i]){
        pq.pop();
        pq.push(arr[i]);
    }
}

cout<<pq.top()<<" ";

return 0 ;
}