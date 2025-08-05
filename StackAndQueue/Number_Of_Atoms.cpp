class Solution {
public:
    string countOfAtoms(string formula) {
        int n=formula.size();
        int i=0;
        stack<unordered_map<string,int>> st;
        st.push(unordered_map<string,int>());
        while(i<n){
            if(formula[i]=='('){
                st.push(unordered_map<string,int>());
                i++;
            }
            else if(formula[i]==')'){
                unordered_map<string,int> curr=st.top();
                st.pop();
                i++;
                string mul;
                while(i<n && isdigit(formula[i])){
                    mul+=formula[i];
                    i++;
                }
                if(!mul.empty()){
                    int multiplier=stoi(mul);
                    for(auto& [atom,count]:curr){
                        curr[atom]=count*multiplier;
                    }
                }
                for(auto& [atom,count]:curr){
                    st.top()[atom]+=count;
                }
            }
            else{
                string atom;
                atom+=formula[i];
                i++;
                while(i<n && isalpha(formula[i]) && islower(formula[i])){
                    atom+=formula[i];
                    i++;
                }
                string freq;
                while(i<n && isdigit(formula[i])){
                    freq.push_back(formula[i]);
                    i++;
                }
                int count;
                if(freq.empty()) count=1;
                else count=stoi(freq);
                st.top()[atom]+=count;
            }
        }
        map<string,int> sortedMap(begin(st.top()),end(st.top()));
        string result;
        for(auto& [atom,count]:sortedMap){
            result+=atom;
            if(count>1) result+=to_string(count);
        }
        return result;
    }
};
