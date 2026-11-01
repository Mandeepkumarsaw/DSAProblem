class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        res = []
        path = []

        def backtrack(open_cnt, close_cnt):
            if len(path) == 2 * n:
                res.append("".join(path))
                return

            if open_cnt < n:
                path.append("(")
                backtrack(open_cnt + 1, close_cnt)
                path.pop()

            if close_cnt < open_cnt:
                path.append(")")
                backtrack(open_cnt, close_cnt + 1)
                path.pop()

        backtrack(0, 0)
        return res