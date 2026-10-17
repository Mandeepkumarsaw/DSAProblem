class Solution:
    def isVowel(self,c:str) -> bool:
        return c in "aeiouAEIOU"

    def reverseVowels(self, s: str) -> str:
        s=list(s)
        left,right = 0,len(s)-1

        while left < right:

            if not self.isVowel(s[right]):
                right -=1
                continue

            if not self.isVowel(s[left]):
                left+=1
                continue    



            s[left],s[right] =s[right],s[left]
            left += 1
            right -=1

        return "".join(s)    


        