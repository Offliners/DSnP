import random
from typing import List

config = {
    # num of testcase
    'num_testcase': 10000,

    # Boundary of commands
    'cmd_lower' : 0,
    'cmd_upper' : 10000,

    # Boundary of stack size
    'size_lower' : 0,
    'size_upper' : 10000,

    # Boundary of value in stack
    'value_lower' : 0,
    'value_upper' : 10000
}

random.seed(config['seed'])

class my_stack:
    def __init__(self, maxsize: int) -> None:
        self.s = []
        self.maxsize = maxsize
        self.cmd_list = ['PUSH', 'POP', 'DISPLAY', 'CHECK', 'IS_EMPTY', 'IS_FULL']

    def push(self, n: int) -> None:
        if len(self.s) < self.maxsize:
            self.s.append(n)
        else:
            print('Full')
    
    def pop(self) -> None:
        if self.s:
            self.s.pop()
        else:
            print('Empty')
    
    def display(self) -> None:
        print(*self.s)
    
    def check(self) -> None:
        print(len(self.s))
    
    def empty(self) -> None:
        if self.s:
            print('False')
        else:
            print('True')
    
    def full(self) -> None:
        if len(self.s) >= self.maxsize:
            print('True')
        else:
            print('False')


def main():
    pass

if __name__ == '__main__':
    main()