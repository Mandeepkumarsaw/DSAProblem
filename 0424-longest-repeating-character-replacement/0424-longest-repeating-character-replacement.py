class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        left = 0
        maxFreq = 0
        ans = 0
        freq = {}
        

        for right in range(len(s)):
            ch = s[right]
            freq[ch] = freq.get(ch,0) + 1

            maxFreq = max(maxFreq,freq[ch])

            while (right-left+1) - maxFreq > k:
                left_ch = s[left]
                freq[left_ch] -= 1
                left += 1

        ans = max(ans,right-left+1)
        return ans        