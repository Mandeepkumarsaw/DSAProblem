class Solution:
    def minimumPushes(self, word: str) -> int:
        freq = {}

        for ch in word:
            freq[ch] = freq.get(ch,0)+1

    
        v=list(freq.values())

        v.sort(reverse=True)

        ans = 0
        for i in range(len(v)):
            ans += (i//8 + 1)*v[i]

        return ans    
        
        
if __name__ == "__main__":  
    sol = Solution()

    # Test cases
    test_words = [
        "hello",                # simple short word
        "abcdefghij",           # 10 distinct letters
        "leetcode",             # repeated letters
        "abcdefghijklmnopqr",   # 17 letters
        "abcdefghijklmnopqrstuvwxyz"  # full alphabet
    ]

    for word in test_words:
        print(f"Word: {word}, Minimum Pushes: {sol.minimumPushes(word)}")     