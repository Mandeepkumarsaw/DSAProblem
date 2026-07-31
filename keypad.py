class Solution:
    def minimumPushes(self, word: str) -> int:
        n=len(word)

        if n <= 8:
            return n
        elif n>8 and n<=16:
            return 8 + (n-8)*2
        elif n>16 and n<=24:
            return 24 + (n-16)*3
        else:
            return 48 + (n-24)*4            
   

if __name__ == "__main__":
    sol = Solution()
    
    
    test_words = ["hello", "abcdefghij", "abcdefghijklmnopqr", "abcdefghijklmnopqrstuvwx", "abcdefghijklmnopqrstuvwxyz"]
    
    for word in test_words:
        print(f"Word: {word}, Length: {len(word)}, Minimum Pushes: {sol.minimumPushes(word)}")        