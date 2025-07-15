//TC - O(2N) , SC - O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int left=0,right=0;
        unordered_map<char,int> mpp;
        int count=0;
        while(right<n){
            mpp[s[right]]++;
            while(mpp.size()==3){
                count+=n-right;
                mpp[s[left]]--;
                if(mpp[s[left]]==0) mpp.erase(s[left]);
                left++;
            }
            right++;
        }
        return count;
    }
};

//TC - O(N) , SC - O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        vector<int> hash={-1,-1,-1};
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']=i;
            if(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1){
                count+=1+min({hash[0],hash[1],hash[2]});
            }
        }
        return count;
    }
};
