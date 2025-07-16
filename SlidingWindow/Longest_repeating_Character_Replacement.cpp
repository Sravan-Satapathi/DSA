//TC - O(2N*26)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxFreq=0;
        int left=0,right=0;
        vector<int> hash(26,0);
        int result=0;
        while(right<n){
            hash[s[right]-'A']++;
            maxFreq=max(maxFreq,hash[s[right]-'A']);
            int currLen=right-left+1;
            while(currLen-maxFreq>k){
                hash[s[left]-'A']--;
                for(int i=0;i<26;i++) maxFreq=max(maxFreq,hash[i]);
                left++;
                currLen--;
            }
            result=max(result,right-left+1);
            right++;
        }
        return result;
    }
};


//TC - O(2N)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxFreq=0;
        int left=0,right=0;
        vector<int> hash(26,0);
        int result=0;
        while(right<n){
            hash[s[right]-'A']++;
            maxFreq=max(maxFreq,hash[s[right]-'A']);
            int currLen=right-left+1;
            while(currLen-maxFreq>k){
                hash[s[left]-'A']--;
                left++;
                currLen--;
            }
            result=max(result,right-left+1);
            right++;
        }
        return result;
    }
};


//TC - O(N)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxFreq=0;
        int left=0,right=0;
        vector<int> hash(26,0);
        int result=0;
        while(right<n){
            hash[s[right]-'A']++;
            maxFreq=max(maxFreq,hash[s[right]-'A']);
            int currLen=right-left+1;
            if(currLen-maxFreq>k){
                hash[s[left]-'A']--;
                left++;
                currLen--;
            }
            if(currLen-maxFreq<=k){
                result=max(result,right-left+1);
            }
            right++;
        }
        return result;
    }
};
