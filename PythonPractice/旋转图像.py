from types import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        half = n // 2
        # 行交换
        for i in range(half):
            matrix[i], matrix[n - 1 - i] = matrix[n - 1 - i], matrix[i]
        # 对角线交换
        for i in range(n):
            for j in range(i + 1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
                