class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        n=len(digits)
        ans = set()

        for i in range(n):
            for j in range(n):
                for k in range(n):

                    if digits[i] == 0:
                        continue
                    if digits[k] % 2 !=0:
                        continue
                    if i==j or j==k or i==k:
                        continue
                    ans.add(digits[i]*100 + digits[j]*10 + digits[k])
        return len(ans)                          
        