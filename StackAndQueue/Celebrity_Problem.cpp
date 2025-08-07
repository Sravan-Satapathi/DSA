class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        int top=0,bottom=n-1;
        while(top<bottom){
            if(mat[top][bottom]==1) top++;
            else if(mat[bottom][top]==1) bottom--;
            else{
                top++,bottom--;
            }
        }
        int celeb=top;
        for(int i=0;i<n;i++){
            if(i==celeb) continue;
            if(mat[i][celeb]==0 || mat[celeb][i]==1) return -1;
        }
        return celeb;
    }
};
