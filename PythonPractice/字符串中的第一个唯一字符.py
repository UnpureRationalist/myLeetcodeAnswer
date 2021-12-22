class Solution:
    def firstUniqChar(self, s: str) -> int:
        ans = -1
        n = len(s)
        mp = dict()
        for char in s:
            if mp.get(char) == None:
                mp[char] = 1
            else:
                mp[char] = mp[char] + 1
        for i in range(n):
            if mp[s[i]] == 1:
                ans = i
                break
        return ans