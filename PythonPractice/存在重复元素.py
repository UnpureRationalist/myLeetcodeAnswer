from types import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        mp = {}
        for i in nums:
            if mp.get(i) != None:
                return True
            else:
                mp[i] = 1
        return False
