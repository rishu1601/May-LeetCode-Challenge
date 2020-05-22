from collections import Counter
class Solution:
    def frequencySort(self, s: str) -> str:
        return "".join([item[0]*item[1] for item in Counter(s).most_common()])
