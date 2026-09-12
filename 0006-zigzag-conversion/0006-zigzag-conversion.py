class Solution:
    def convert(self, s: str, m: int) -> str:
        if m <= 1:
          return s

        ans = [""]*m
        direction=1
        row=0

        for ch in s:
            ans[row] += ch

            if row == 0:
               direction = 1
            elif row == m-1:
               direction = -1     


            row += direction
        return "".join(ans)    
        