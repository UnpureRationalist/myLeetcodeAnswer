from types import List


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = []
        nums1.sort()
        nums2.sort()
        n1 = len(nums1)
        n2 = len(nums2)
        i = 0
        j = 0
        while i < n1 and j < n2:
            if nums1[i] == nums2[j]:
                ans.append(nums1[i])
                i += 1
                j += 1
                # value = nums1[i]
                # while i < n1 and nums1[i] == value:
                #     i += 1
                # while j < n2 and nums2[j] == value:
                #     j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        return ans
