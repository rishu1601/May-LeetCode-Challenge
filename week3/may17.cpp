
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
     vector<int> pt(26, 0);
        int i;
        vector<int> st(26,0);
        vector<int> ans;
        if(p.size() > s.size()) return ans;
        for(i = 0; i < p.size(); i++)pt[p[i] - 'a']++;
        for(i = 0; i < p.size() - 1; i++)st[s[i] - 'a']++;
        for(i = p.size() - 1; i < s.size(); i++) {
            st[s[i] - 'a']++;
            if(i >= p.size()){
                st[s[i - p.size()] - 'a'] --;
            }
            bool isOk = true;
            for(int j = 0; j < 26; j++) {
                if(st[j] != pt[j]){
                    isOk = false;
                    break;
                }
            }
            if(isOk)ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};
