import os
import random
from config import config
from typing import List, Tuple

class bcolors:
    OKGREEN = '\033[92m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'

cmd_list = [
    'PUSH',
    'POP',
    'DISPLAY',
    'CHECK',
    'IS_EMPTY',
    'IS_FULL'
]

random.seed(config['seed'])

class my_stack:
    def __init__(self, maxsize: int, result: List[str]) -> None:
        self.s = []
        self.maxsize = maxsize
        self.result = result

    def push(self, n: int) -> None:
        if len(self.s) < self.maxsize:
            self.s.append(n)
        else:
            self.result.append('Full')
    
    def pop(self) -> None:
        if self.s:
            self.s.pop()
        else:
            self.result.append('Empty')
    
    def display(self) -> None:
        result_str = [str(e) for e in self.s]
        self.result.append(" ".join(result_str))
    
    def check(self) -> None:
        self.result.append(str(len(self.s)))
    
    def empty(self) -> None:
        if self.s:
            self.result.append('False')
        else:
            self.result.append('True')
    
    def full(self) -> None:
        if len(self.s) >= self.maxsize:
            self.result.append('True')
        else:
            self.result.append('False')

    def get_result(self) -> List[str]:
        return self.result


def gen() -> Tuple[List[str], List[str]]:
    testcase_input = []
    testcase_output = []

    num_cmd = random.randint(config['cmd_lower'], config['cmd_upper'])
    cmd_weights = [config['prob_push'], config['prob_pop'], config['prob_display'], config['prob_check'], config['prob_is_empty'], config['prob_is_full']]
    testcase_input.append(str(num_cmd))
    
    stack_maxsize = random.randint(config['size_lower'], config['size_upper'])
    testcase_input.append(str(stack_maxsize))
    s = my_stack(stack_maxsize, testcase_output)
    for _ in range(num_cmd):
        cmd = random.choices(cmd_list, weights=cmd_weights)[0]
        if cmd == cmd_list[0]:
            n = random.randint(config['value_lower'], config['value_upper'])
            cmd = cmd + f' {n}'
            s.push(n)
        elif cmd == cmd_list[1]:
            s.pop()
        elif cmd == cmd_list[2]:
            s.display()
        elif cmd == cmd_list[3]:
            s.check()
        elif cmd == cmd_list[4]:
            s.empty()
        elif cmd == cmd_list[5]:
            s.full()
        else:
            print(f'{bcolors.FAIL}Unknown command{bcolors.ENDC}')

        testcase_input.append(cmd)

    return testcase_input, s.get_result()
        

def main(input_path: str, output_path: str) -> None:
    num_testcase = config['num_testcase']
    for i in range(num_testcase):
        input, output = gen()

        input_path_index = os.path.join(input_path, f'{i}.in')
        with open(input_path_index, 'w') as f_in:
            for line in input:
                f_in.writelines(f'{line}\n')
        
        output_path_index = os.path.join(output_path, f'{i}.out')
        with open(output_path_index, 'w') as f_out:
            for line in output:
                f_out.writelines(f'{line}\n')

        print(f'{bcolors.OKGREEN}Pattern no.{i} done!{bcolors.ENDC}')


if __name__ == '__main__':
    input_path = './input'
    output_path = './golden_output'
    os.makedirs(input_path, exist_ok=True)
    os.makedirs(output_path, exist_ok=True)
    main(input_path, output_path)