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


 int countLength(vector<int>&arr){
    stack<int>s;
    s.push(0);

    vector<int>temp;
    temp.pb(0);
    for(auto i:arr){
        temp.push_back(i);
    }
    arr=temp;
    int maxi=INT_MIN;
    for(int i=1;i<arr.size();i++){
        if(arr[i]>0){
            s.push(i);
        }
        else{
            int index=s.top();s.pop();

            if(arr[index]==-arr[i]){
                maxi=max(maxi,i-s.top());
            }
            else{
                s.push(i);
            }
        }
    }

    return maxi;
 }

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


vector<int>arr={1,-1,2,-2,6,4,-4,5,-5,6,7,-7,-6,8,-9,10};

cout<<countLength(arr);
return 0 ;
}