
class Solution {
    int n,m;
    bool isValid(int sr,int sc) {
        return (sr >= 0 && sr < n) && (sc >= 0 && sc < m);
    }
    void dfs(vector<vector<int>>& image,
                   int sr,
                   int sc,
                    int currColor,
                   int newColor) {
        if(!isValid(sr,sc)) return;
        if(image[sr][sc] != currColor)return;
        image[sr][sc] = newColor;
        dfs( image, sr - 1, sc, currColor, newColor);
        dfs( image, sr + 1, sc, currColor, newColor);
        dfs( image, sr, sc + 1, currColor, newColor);
        dfs( image, sr, sc - 1, currColor, newColor);
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();
        if(image[sr][sc] != newColor)dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};
