class Solution:
    def reverse(self, x: int) -> int:
        ans = 0
        if x == 0:
            ans = 0
        elif x < 0:
            x = -x
            s = str(x)
            s = s[::-1]
            x = int(s)
            ans = -x
        else:
            ans = int(str(x)[::-1])
        if ans >= -2**31 and ans <= 2**31 - 1:
            return ans
        else:
            return 0