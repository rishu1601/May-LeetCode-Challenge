class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <= 1)return true;
        int low = 2, high = num / 2;
        while( low <= high) {
            double mid = low + (high - low) / 2;
            if(mid == num/ mid)return true;
            if( mid * mid < num) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
};
