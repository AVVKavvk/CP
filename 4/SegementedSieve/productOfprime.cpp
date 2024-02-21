class Solution{
public:
int sieve[1000005];
void createSieve(){
    int n=1000000;
 for(int i=2;i<=n;i++) sieve[i]=1;

 for(int i=2;i*i<=n;i++){
    if(sieve[i]==1){
        for(int j=i*i;j<=n;j+=i){
            sieve[j]=0;
        }
    }
 }
}
 
long long segementedSieve( long long r,long long l){

    createSieve();   // step 1

    // int l,r;
    // cin>>l>>r;

    vector<int>primes;
                               // step 2 collect  primes number before sort(r)
    for(int i=2;i*i<=r;i++){
        if(sieve[i]==1) primes.push_back(i);
    }
    
    int dummy[r-l+1];       // step 3  create dummy arrry of size r-l
    for(int i=0;i<r-l+1;i++) dummy[i]=1;
    
    for(auto pr:primes){            // mark primes mul as false

        long long firstMultiple= (l/pr) *pr;
        if(l%pr!=0) firstMultiple+=pr;

        for(int j=max(firstMultiple, 1ll*pr*pr);j<=r;j+=pr){
            dummy[j-l]=0;   // 0 based indexing
        }
    }

    // int cnt=0;
    // vector<int>ans;
   long long ans=1;
    for(int i=l;i<=r;i++){
        if(dummy[i-l]==1) {
            ans*=i;
        }
    }
   return ans;

}
    long long primeProduct(long long L, long long R){
        // code here
        
        return segementedSieve(R,L);
    }
};