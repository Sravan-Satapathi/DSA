//TC - O(2N)
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26,0);
        int left=0,right=0,max_len=0;
        int max_freq=0;
        while(right<s.size()){
            hash[s[right]-'A']++;
            max_freq=max(max_freq,hash[s[right]-'A']);
            int curr_len=right-left+1;
            while(curr_len-max_freq>k){
                hash[s[left]-'A']--;
                left++;
                curr_len-=1;
            }
            max_len=max(max_len,curr_len);
            right++;
        }
        return max_len;
    }
};

//TC - O(N)
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26,0);
        int left=0,right=0,max_len=0;
        int max_freq=0;
        while(right<s.size()){
            hash[s[right]-'A']++;
            max_freq=max(max_freq,hash[s[right]-'A']);
            int curr_len=right-left+1;
            if(curr_len-max_freq>k){
                hash[s[left]-'A']--;
                left++;
            }
            if(curr_len-max_freq<=k){
                max_len=max(max_len,curr_len);
            }
            right++;
        }
        return max_len;
    }
};
