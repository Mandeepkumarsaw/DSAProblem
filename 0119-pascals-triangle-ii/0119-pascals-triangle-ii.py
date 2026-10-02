class Solution(object):
    def getRow(self, rowIndex):
        last_row = [1]
        for i in range(1, rowIndex + 1):
            curr = [1] * (i + 1)
            for j in range(1, i):
                curr[j] = last_row[j] + last_row[j - 1]
            last_row = curr
        return last_row

        