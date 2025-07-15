class Solution {
  private:
    vector<int> getSieve(int n){
        vector<int> sieve(n+1,1);
        sieve[0]=sieve[1]=0;
        for(int i=2;i*i<=n;i++){
            if(sieve[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    sieve[j]=0;
                }
            }
        }
        return sieve;
    }
  public:
    int countPrimes(int L, int R) {
        // code here
        int n=2*10e5;
        vector<int> sieve=getSieve(n);
        for(int i=2;i<=n;i++){
            sieve[i]=sieve[i]+sieve[i-1];
        }
        return sieve[R]-sieve[L-1];
    }
};
