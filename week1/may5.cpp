class Solution {
    struct charOcc{
        int frequency;
        int firstIndex;
    };
    public:
    int firstUniqChar(string s) {
        vector<charOcc> chars(26);
        for(int i = 0; i < s.size(); i++) {
            int ind = s[i]-'a';
            if(chars[ind].frequency == 0) {
                chars[ind].firstIndex = i;
            }
            chars[ind].frequency += 1;
        }
        int minIndex = s.size();
        for(int i = 0; i < 26; i++) {
            if(chars[i].frequency == 1){
                minIndex = min(minIndex, chars[i].firstIndex);
            }
        }
        if(minIndex == s.size()) return -1;
        return minIndex;
    }
};
