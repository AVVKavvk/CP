

/*You are required to complete this method */
int computeHash(string s){
    long long pr=1;
    long  long hash=0;
    int mod=1e9+7;
    
    for(auto i:s){
        hash=(hash+ ((i-'a'+1)*pr)%mod)%mod;
        pr=(pr*31)%mod;
    }
    return (int)hash;
}
int countDistinctSubstring(string s)
{
    //Your code here
    unordered_set<long long>st;
    for(int i=0;i<s.size();i++){
            long long pr=1;
            long long pr2=1;
            long  long hash=0;
            int mod=1e9+7;
        for(int j=i;j<s.size();j++){
            
            hash=(hash+ ((s[j]-'a'+1)*pr*pr2));
            pr=(pr*37);
            // pr2=(pr2*7);
            st.insert(hash);
            
        }
    }
    
    return st.size()+1;
}