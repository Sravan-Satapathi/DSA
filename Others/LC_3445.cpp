class Solution {
public:
    int getState(int count_a,int count_b){
        int parity_a=count_a%2;
        int parity_b=count_b%2;
        if(parity_a==0 && parity_b==0) return 0; 
        if(parity_a==0 && parity_b==1) return 1; 
        if(parity_a==1 && parity_b==0) return 2;
        return 3; 
    }
    //main call
    int maxDifference(string s,int k){
        int n=s.length();
        int result=INT_MIN;
        for(char a='0';a<='4';a++){
            for(char b='0';b<='4';b++){
                if(a==b) continue;
                vector<int> stateMinPrev(4,INT_MAX);
                int count_a=0,count_b=0;
                int prev_a=0,prev_b=0;
                int left=-1,right=0;
                while(right<n){
                    if(s[right]==a) count_a+=1;
                    if(s[right]==b) count_b+=1;
                    while(right-left>=k && count_b-prev_b>=2 && count_a-prev_a>=1){
                        int leftState=getState(prev_a,prev_b);
                        stateMinPrev[leftState]=min(stateMinPrev[leftState],prev_a-prev_b);
                        left++;
                        if(s[left]==a) prev_a+=1;
                        if(s[left]==b) prev_b+=1;
                    }
                    int rightState=getState(count_a,count_b);
                    int bestLeftState=rightState^2;
                    int bestMinDiffValueLeft=stateMinPrev[bestLeftState];
                    if(bestMinDiffValueLeft!=INT_MAX){
                        result=max(result,(count_a-count_b)-bestMinDiffValueLeft);
                    }
                    right++;
                }
            }
        }
        return result;
    }
};
