class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool> mpp;
        for(int i=0;i<wordList.size();i++){
            mpp[wordList[i]]=true;
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        mpp.erase(beginWord);
        while(!q.empty()){
            string str=q.front().first;
            int len=q.front().second;
            q.pop();
            if(str==endWord) return len;
            for(int i=0;i<str.size();i++){
                char original=str[i];
                for(char c='a';c<='z';c++){
                    str[i]=c;
                    if(mpp.find(str)!=mpp.end()){
                        q.push({str,len+1});
                        mpp.erase(str);
                    }
                }
                str[i]=original;
            }
        }
        return 0;
    }
};
