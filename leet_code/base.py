class BaseSolution:
    def input(self):
        pass

    def solution(self):
        pass

    def output(self):
        pass

    def solve(self, input_file):
        print(input_file)
        input_list = self.input(input_file)
        print(input_list)
        result = self.solution(*input_list)
        self.output(result)
