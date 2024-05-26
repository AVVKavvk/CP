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
#define limit(x) x.begin(),x.end()


ll bTD(){ string s;cin>>s;ll num=0;
for(auto ch:s){if(ch=='1')num = num*2 + 1;else num=num*2;}
return num;}; 
bool pOf2(ll num){if(num<=0) return false;if((num&(num-1))==0) return true;else return false;}
 

 void MIM(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int S;
    cin>>S;

    vector<int> arr1;
    vector<int>arr2;
    for(int i=0;i<n/2;i++) arr1.push_back(arr[i]);
    for(int i=n/2;i<n;i++) arr2.push_back(arr[i]);

    int n1=arr1.size();
    int n2=arr2.size();

    vector<int>temp;

    unordered_map<int,int>mpp;

    for(int i=0;i<(1<<n1);i++){
        int sum=0;
        for(int j=0;j<n1;j++){
            if(i&(1<<j)) sum+=arr1[j];
        }
        temp.push_back(sum);
    }
    for(int i=0;i<(1<<n2);i++){
        int sum=0;
        for(int j=0;j<n2;j++){
            if(i&(1<<j)) sum+=arr2[j];
        }
        mpp[sum]++;
    }
    int cnt=0;
    int size=temp.size();
    for(int i=0;i<size;i++){
        cnt+=mpp[S-temp[i]];
    }
    cout<< cnt<<endl;

 }

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


                              // *          where  n<=36     and   sum==S
                         //? we divide out array into two  parts and sol individualy


int t=1;
// cin>>t;
while(t--){ 

MIM();

}
return 0 ;
}

//  vector<int> nums = {1, 2, 3, 4, 6, 7,12,11,13,5};
//     int target = 22;