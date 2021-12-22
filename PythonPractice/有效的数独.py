from types import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = 9
        rows = [0, 3, 6]
        rows_end = [3, 6, 9]
        cols = rows
        cols_end = rows_end
        # row
        for i in range(n):
            mp = dict()
            for j in range(n):
                char = board[i][j]
                if char != '.' and mp.get(char) != None:
                    return False
                else:
                    mp[char] = 1
        # col
        for j in range(n):
            mp = dict()
            for i in range(n):
                char = board[i][j]
                if char != '.' and mp.get(char) != None:
                    return False
                else:
                    mp[char] = 1
        # 3*3
        for i in range(3):
            row_start = rows[i]
            row_end = rows_end[i]
            for j in range(3):
                col_start = cols[j]
                col_end = cols_end[j]
                mp = dict()
                for row in range(row_start, row_end):
                    for col in range(col_start, col_end):
                        char = board[row][col]
                        if char != '.' and mp.get(char) != None:
                            return False
                        else:
                            mp[char] = 1

        return True
