class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int> actualIndex(n);
        for(int i=0;i<n;i++){
            actualIndex[i]=i;
        }
        auto lambda=[&](int& a,int&b){
            return positions[a]<positions[b];
        };
        sort(actualIndex.begin(),actualIndex.end(),lambda);
        stack<int> st;
        for(int i=0;i<n;i++){
            int ind=actualIndex[i];
            if(directions[ind]=='R') st.push(ind);
            else{
                while(!st.empty() && directions[st.top()]=='R' && healths[ind]>0){
                    int topIndex=st.top();
                    if(healths[topIndex]==healths[ind]){
                        healths[topIndex]=healths[ind]=0;
                        st.pop();
                    }
                    else if(healths[topIndex]<healths[ind]){
                        healths[topIndex]=0;
                        healths[ind]--;
                        st.pop();
                    }
                    else{
                        healths[ind]=0;
                        healths[topIndex]--;
                    }
                }
            }
        }
        vector<int> result;
        for(int i=0;i<n;i++){
            if(healths[i]>0){
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};
