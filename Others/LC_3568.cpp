class Solution {
private:
    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;

    struct State{
        int row;
        int col;
        int remainingEnergy;
        int litterMask;
    };
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<vector<int>> litterBitMask(m, vector<int>(n,-1));
        int totalLitter = 0;
        int startRow, startCol;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(classroom[i][j] == 'S'){
                    startRow = i;
                    startCol = j;
                }
                if(classroom[i][j] == 'L'){
                    litterBitMask[i][j] = totalLitter;
                    totalLitter++;
                }
            }
        }

        if(totalLitter == 0) return 0;

        queue<pair<State,int>> q;
        int completeLitter = (1<<totalLitter)-1;
        VVVVB visited(m, VVVB(n, VVB(energy+1, VB(completeLitter+1, false))));

        q.push({{startRow, startCol, energy, 0},0});
        visited[startRow][startCol][energy][0] = true;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};

        while(!q.empty()){
            State s = q.front().first;
            int moves = q.front().second;
            q.pop();
            int row = s.row, col = s.col;
            int remEnergy = s.remainingEnergy;
            int bitMask = s.litterMask;

            if(bitMask == completeLitter) return moves;
            if(remEnergy == 0) continue;

            for(int i=0; i<4; i++){
                int r = row+dr[i];
                int c = col+dc[i];
                if(r>=0 && r<m && c>=0 && c<n && classroom[r][c]!='X'){
                    int newEnergy = remEnergy-1;
                    int newMask = bitMask;
                    if(classroom[r][c] == 'R'){
                        newEnergy = energy;
                    }
                    else if(classroom[r][c] == 'L'){
                        newMask = newMask | (1<<litterBitMask[r][c]);
                    }

                    if(!visited[r][c][newEnergy][newMask]){
                        visited[r][c][newEnergy][newMask] = true;
                        q.push({{r,c,newEnergy,newMask},moves+1});
                    }

                }
            }
        }

        return -1;

    }
};
