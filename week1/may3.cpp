//Ransom Note
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> occ(26, 0);
        for(char c: magazine) occ[c-'a']++;
        for(char c: ransomNote){
            occ[c - 'a']--;
            if(occ[c-'a'] < 0)return false;
        }
        return true;
    }
};
