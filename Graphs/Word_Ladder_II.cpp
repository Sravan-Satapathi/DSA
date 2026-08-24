class Solution {
  public:
    vector<vector<string>> findSequences(vector<string> &words, string &s, string &e) {
        // code here
        unordered_set<string> wordsList(words.begin(),words.end());
        vector<vector<string>> result;
        queue<vector<string>> q;
        q.push({s});
        
        unordered_set<string> usedOnLevel;
        usedOnLevel.insert(s);
        int level = 0;
        
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            
            if(vec.size()>level){
                level++;
                for(auto it : usedOnLevel){
                    wordsList.erase(it);
                }
                usedOnLevel.clear();
            }
            
            string curr = vec.back();
            if(curr == e){
                result.push_back(vec);
                continue;
            }
            
            for(int i=0; i<curr.size(); i++){
                char original = curr[i];
                for(char c='a'; c<='z'; c++){
                    curr[i] = c;
                    if(wordsList.find(curr)!=wordsList.end()){
                        vec.push_back(curr);
                        q.push(vec);
                        usedOnLevel.insert(curr);
                        vec.pop_back();
                    }
                }
                curr[i] = original;
            }
        }
        
        return result;
    }
};
