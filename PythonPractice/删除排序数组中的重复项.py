from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count = 0
        temp = list()
        if len(nums) > 0:
            temp.append(nums[0])
            count = 1
        for i in range(1, len(nums), 1):
            if nums[i] != temp[-1]:
                temp.append(nums[i])
                count += 1
        nums[:] = temp
        return count

if __name__ == '__main__':
    s = Solution()
    lst = [1, 2, 2, 3]
    temp = s.removeDuplicates(lst)
    print(temp)
    print(lst)
