class Solution:
    def uniqueMorseRepresentations(self, words: list[str]) -> int:
        morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

        ans = set()

        for w in words:
            code = ""
            for ch in w:
                code  += morse[ord(ch)-ord('a')]
            ans.add(code)

        return len(ans)        
        