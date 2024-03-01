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

vector<int> calNGE(vector<int>arr){
    stack<int>st;
    vector<int>temp;
    st.push(-1);
    for(int i=arr.size()-1;i>=0;i--){
        while(!st.empty() && st.top()>=arr[i]) st.pop();
        if(st.empty()) {
            temp.push_back(-1);
            st.push(arr[i]);
        }
        else {
            temp.push_back(st.top());
            st.push(arr[i]);
        }
        
    }
    reverse(temp.begin(),temp.end());
    return temp;
}
 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


vector<int>arr={5,2,7,6,7,8,11,13,15,14,17,16};
vector<int>temp=calNGE(arr);
for(auto i:temp) cout<<i<<" ";
return 0 ;
}