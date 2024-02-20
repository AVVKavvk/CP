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
 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int arr[7]={2,3,5,8,11,13,16};
sort(arr,arr+7);
int e=arr[6]+1;
int s=1;
int GivenSum=10;
int k=-1;
while(s<=e){
    int mid=s+(e-s)/2;
    int sum=0;
    for(int i=0;i<7;i++) sum+=arr[i]/mid;
    if(sum<=GivenSum){
        k=mid;
        e=mid-1;

    }
    else s=mid+1;
}

cout<<k;
return 0 ;
}