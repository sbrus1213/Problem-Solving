"""A solution code for problem [576. Out of Boundary Paths] of leetcode

https://leetcode.com/problems/out-of-boundary-paths/
This module is written for problem 695 of leetcode. That problem wants
to find the number of cases in which a ball on a 2dimensional grid can
move out of the grid by moving up to maxMove times.

  Typical usage example:

  from 576 import Solution

  Solution.mfindPath(2, 2, 2, 0, 0)
"""

from base import BaseSolution


class Solution(BaseSolution):
    def __init__(self):
        self.solution = self.findPaths

    def input(self, input_file):
        inputs = []

        with open(input_file, 'r') as fp:
            for i in range(5):
                inputs.append(int(fp.readline()))

        return inputs

    def output(self, result):
        print(result)

    def findPaths(self, m: int, n: int, maxMove: int, startRow: int,
                  startColumn: int) -> int:
        if maxMove == 0:
            return 0

        di = [1, 0, -1, 0]
        dj = [0, 1, 0, -1]
        limit = int(1e9 + 7)

        counts = [
            [
                [0 for k in range(maxMove)]
                for j in range(n)
            ]
            for i in range(m)
        ]
        for i in range(m):
            counts[i][0][0] += 1
            counts[i][n-1][0] += 1
        for j in range(n):
            counts[0][j][0] += 1
            counts[m-1][j][0] += 1

        for c in range(1, maxMove):
            for i in range(m):
                for j in range(n):
                    for k in range(4):
                        ni = i + di[k]
                        nj = j + dj[k]
                        if ni < 0 or ni >= m:
                            continue
                        if nj < 0 or nj >= n:
                            continue
                        counts[i][j][c] = \
                            (counts[i][j][c] + counts[ni][nj][c-1]) % limit

        ans = 0
        for k in range(maxMove):
            ans = (ans + counts[startRow][startColumn][k]) % limit

        return ans
