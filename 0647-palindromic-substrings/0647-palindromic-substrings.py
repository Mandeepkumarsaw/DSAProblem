class Solution:
    def countSubstrings(self, s: str) -> int:
        n=len(s)
        res=[]
        ans=[]
        for i in range(n):
            for j in range(i+1,n+1):
                res.append(s[i:j])

        for i in res:
            if i==i[::-1]:
                ans.append(i)
        return len(ans)

                

        