"""A solution code for problem [695. Max Area of Island] of leetcode

https://leetcode.com/problems/max-area-of-island/
This module is written for problem 695 of leetcode. That problem wants
to find the maximum area of 1s connected in 4 direction in a 2 dimensional
grid.

  Typical usage example:

  from 695 import Solution

  Solution.maxAreaOfIsland([[0, 0, 1, 1, 0]])
"""

from ast import literal_eval
from typing import List

from base import BaseSolution


class Solution(BaseSolution):
    def __init__(self):
        self.solution = self.maxAreaOfIsland

    def input(self, input_file):
        inputs = []

        with open(input_file, 'r') as fp:
            grid = fp.readline()
            inputs.append(literal_eval(grid))

        return inputs

    def output(self, result):
        print(result)

    di = [-1, 0, 1, 0]
    dj = [0, -1, 0, 1]

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        max_area = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] != 1:
                    continue

                grid[i][j] = 2
                cur_area = 0
                stack = [(i, j)]

                while stack:
                    cur_area += 1
                    cur_i, cur_j = stack.pop()
                    for k in range(4):
                        ni = cur_i + self.di[k]
                        nj = cur_j + self.dj[k]
                        if ni < 0 or ni >= n:
                            continue
                        if nj < 0 or nj >= m:
                            continue
                        if grid[ni][nj] == 1:
                            grid[ni][nj] = 2
                            stack.append((ni, nj))

                max_area = max(max_area, cur_area)

        return max_area
