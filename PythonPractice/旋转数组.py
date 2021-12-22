from types import List


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        temp = nums[:]
        n = len(nums)
        k = k % n
        for i in range(n):
            temp[(i + k) % n] = nums[i]
        nums[:] = temp
