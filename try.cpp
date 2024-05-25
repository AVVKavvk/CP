#include<bits/stdc++.h>
using namespace std ; 
#define pi 3.14
#define ll long long
#define limit(x) (x.begin(),x.end())


 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n=0;
// cin>>n;
// cin.ignore();
string s;
getline(cin,s);

stringstream ss(s);

vector<int>v;

int i;
while(ss>>i){
    v.push_back(i);
}
cout<<n<<endl;
for(auto i:v) cout<<i<<" ";
return 0 ;
}