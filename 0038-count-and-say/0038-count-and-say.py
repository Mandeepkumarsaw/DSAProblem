class Solution(object):
    def countAndSay(self, n):
        
        def rle(s):
            i = 0
            result = ""
            while i<len(s):
                count =1
                while i+1<len(s) and s[i+1] ==s[i]:
                    count+=1
                    i+=1
                result+=str(count) + s[i]
                i+=1
            return result
        ans = "1"
        for i in range(n-1):
            ans = rle(ans)
        
        return ans