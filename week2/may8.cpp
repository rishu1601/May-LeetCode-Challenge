class Solution {
private:
    inline int gcd(int a, int b){return (b == 0) ? a: gcd(b, a % b); }
    
    pair<int, int> getSlope(vector<int> &p1, vector<int> &p2) {
        int x = p1[0] - p2[0];
        int y = p1[1] - p2[1];
        int gc = gcd(x, y);
        return {x/gc, y/gc};
    }
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n <= 2)return true;
        pair<int, int> initialSlope = getSlope(coordinates[0], coordinates[1]);
        for(int i = 1; i < n - 1; i++){
            pair<int, int> currSlope = getSlope(coordinates[i], coordinates[i + 1]);
            if(currSlope != initialSlope)
                return false;
        }
        return true;
    }
};
