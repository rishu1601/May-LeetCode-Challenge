/**
 Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

 Note:
 The length of num is less than 10002 and will be ≥ k.
 The given num does not contain any leading zero.
 Example 1:

 Input: num = "1432219", k = 3
 Output: "1219"
 Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
 Example 2:

 Input: num = "10200", k = 1
 Output: "200"
 Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
 Example 3:

 Input: num = "10", k = 2
 Output: "0"
 Explanation: Remove all the digits from the number and it is left with nothing which is 0.

 */

class Solution {
private:
    string removeLeadingZeroes(string s) {
        int i = 0;
        int n = s.size();
        while(s[i] == '0'){
            i++;
        }
        if(i == n){
            return "0";
        }
        string ans = "";
        for(int j = i; j < n; j++) {
            ans += s[j];
        }
        return ans;
    }
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        int j = 0;
        for(char c: num) {
            while(!st.empty() && j < k && st.top() > c) {
                j += 1;
                st.pop();
            }
            st.push(c);
        }
        while(!st.empty() && j < k) {
            st.pop();
            j += 1;
        }
        string s = "";
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return removeLeadingZeroes(s);
    }
};
