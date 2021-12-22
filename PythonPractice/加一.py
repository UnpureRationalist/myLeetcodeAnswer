from types import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        ans = digits[-1] + 1
        sum = ans % 10
        pro = ans // 10
        digits[-1] = sum
        n = len(digits)
        i = n - 2
        while pro != 0:
            ans = pro + digits[i]
            pro = ans // 10
            sum = ans % 10
            if i < 0:
                digits.insert(0, sum)
                pro = 0
            else:
                digits[i] = sum
            i -= 1
        return digits

