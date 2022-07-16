#! /Users/gh/.pyenv/versions/ps/bin/python3

import sys

from importlib import import_module


difficulty = sys.argv[1]
problem_num = sys.argv[2]

solution = import_module(f'{difficulty}.{problem_num}').Solution()

solution.solve(f'./{difficulty}/{problem_num}.in')
