class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        
        i=len(num1)-1
        j=len(num2)-1
        res = []
        carry = 0

        while i>=0 or j>=0 or carry:
            a = int(num1[i]) if i>=0 else 0 
            b = int(num2[j]) if j>=0 else 0

            total = a+b+carry
            res.append(str(total%10))
            carry = total//10
                    

            i-=1
            j-=1

        return "".join(reversed(res))                        
        