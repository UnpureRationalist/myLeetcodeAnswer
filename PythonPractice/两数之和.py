from types import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict_num = dict()
        for i, v in enumerate(nums):
            tmp = target - v
            if dict_num.get(tmp) is not None:
                return i, dict_num[tmp]
            else:
                dict_num[v] = i
        return 0, 0
        