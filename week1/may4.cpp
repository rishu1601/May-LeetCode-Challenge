class Solution {
    public int findComplement(int num) {
        String binaryNum = Integer.toString(num, 2);
        long curr = 1;
        long ans = 0;
        for(int i = binaryNum.length() - 1; i >= 0 ; i--){
            if(binaryNum.charAt(i)=='0'){
                ans += curr;
            }
            curr = curr * 2;
        }
        return (int)ans;
    }
}
