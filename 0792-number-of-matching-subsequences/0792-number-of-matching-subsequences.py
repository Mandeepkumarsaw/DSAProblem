class Solution:
    def numMatchingSubseq(self, s: str, words: list[str]) -> int:
        pos = defaultdict(list)

        for i, ch in enumerate(s):
            pos[ch].append(i)

        def is_subsequence(word):
            prev = -1

            for ch in word:
                if ch not in pos:
                    return False

                idx = bisect_right(pos[ch], prev)

                if idx == len(pos[ch]):
                    return False

                prev = pos[ch][idx]

            return True

        return sum(is_subsequence(word) for word in words)