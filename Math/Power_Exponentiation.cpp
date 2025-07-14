class Solution {
public:
    double myPow(double x, int n) {
        bool neg=false;
        if(n<0){
            n*=-1;
            neg=true;
        }
        double ans=1.0;
        while(n>0){
            if(n%2==1){
                ans*=x;
                n--;
            }
            else{
                n/=2;
                x*=x;
            }
        }
        if(neg) ans=1.0/ans;
        return ans;
    }
};
