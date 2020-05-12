static int x = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
class Solution {
public:
     int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> indeg(N + 1, 0);
         for(int i = 0; i < trust.size(); i++) {
             --indeg[trust[i][0]];
             ++indeg[trust[i][1]];
         }
         for(int i = 1; i <= N; i++) {
             if(indeg[i] == N - 1)
                 return i;
         }
         return -1;
    }
};
