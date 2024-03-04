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
#define cig(lps,n)   cin.getline(lps,n) 
#define sza(a) sizeof(a)/sizeof(int)
#define vec vector<char> 
#define v2e vector <vector<int> > 
#define v2ec vector <vector<char> >
#define vei vector<int> 
#define pu(n) push_back( n); 
#define ll long long
#define limit(x) (x.begin(),x.end())

void createPrefix(int lps[],string s){

    int len=0;
    int i=1;
    int n=s.size();

    while(i<n){

        if(s[len]==s[i]){
            len++;
            lps[i]=len;
            i++;

        }
        else{

            if(len!=0) len=lps[len-1];
            else {
                lps[i]=0;
                i++;
            }
        }
    }
}
 

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


string s;
cin>>s;
string pattern;
cin>>pattern;

s=pattern + '$' + s;
// cout<<s<<endl;
int n=s.size();
int lps[n]={0};
createPrefix(lps,s);

int cnt=0;
vector<int>ans;

int patternLength=pattern.size();

for(int i=patternLength+1;i<n;i++){
    if(lps[i]==patternLength){
        cnt++;
        ans.pb(i-patternLength-patternLength+1);
    }
}

cout<<cnt<<endl;
for(auto i:ans) cout<<i<<" ";
nl;
return 0 ;
}


// aabbaabbccccaabb
// aabb