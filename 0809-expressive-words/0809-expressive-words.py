class Solution:
    def expressiveWords(self, s: str, words: list[str]) -> int:

        def stretchy(word):
            i = j = 0

            while i < len(s) and j < len(word):
                if s[i] != word[j]:
                    return False

                i1, j1 = i, j

                while i < len(s) and s[i] == s[i1]:
                    i += 1

                while j < len(word) and word[j] == word[j1]:
                    j += 1

                len_s = i - i1
                len_w = j - j1

                if len_s < len_w:
                    return False

                if len_s != len_w and len_s < 3:
                    return False

            return i == len(s) and j == len(word)

        return sum(stretchy(word) for word in words)