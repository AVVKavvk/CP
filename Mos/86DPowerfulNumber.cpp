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
#define ll long long int
#define limit(x) (x.begin(),x.end())


struct node
{
    /* data */
    int l,r,cnt;
}Q[200005];
 
int blockSize=450;
// int blockSize=174;
 bool cmp( node a, node b){
          if(a.l/blockSize!=b.l/blockSize){
            return a.l/blockSize<b.l/blockSize;
          }
          else return a.r<b.r;
 }



int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);


int n,q;
cin>>n>>q;
int arr[n];
for(int i=0;i<n;i++)cin>>arr[i];

for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    l--;r--;
    Q[i].l=l;Q[i].r=r;Q[i].cnt=i;
}

sort(Q,Q+q,cmp);

vector<int>freq(1000005,0);
ll sum=0;
int left=0,right=0;
vector< ll >ans(q);
for(int i=0;i<q;i++){
    auto  it=Q[i];
    int l=it.l;int r=it.r;
    int cnt=it.cnt;

    while(right<=r){
        sum-=1ll*freq[arr[right]]*freq[arr[right]]*arr[right];
        freq[arr[right]]++;
        sum+=1ll*freq[arr[right]]*freq[arr[right]]*arr[right];
        right++;
    }

    while(right>r+1){
        right--;
        sum-=1ll*freq[arr[right]]*freq[arr[right]]*arr[right];
        freq[arr[right]]--;
        sum+=1ll*freq[arr[right]]*freq[arr[right]]*arr[right];
    }

    while(left<l){
        sum-=1ll*freq[arr[left]]*freq[arr[left]]*arr[left];
        freq[arr[left]]--;
        sum+=1ll*freq[arr[left]]*freq[arr[left]]*arr[left];
        left++;
    }
    while(left>l){
        left--;
        sum-=1ll*freq[arr[left]]*freq[arr[left]]*arr[left];
        freq[arr[left]]++;
        sum+=1ll*freq[arr[left]]*freq[arr[left]]*arr[left];
    }
    ans[cnt]=sum;
}
for(int i=0;i<q;i++){
    printf("%I64d\n",ans[i]);
}

return 0 ;
}