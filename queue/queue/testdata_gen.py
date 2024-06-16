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
    'GET_FRONT',
    'DISPLAY',
    'CHECK',
    'IS_EMPTY',
    'IS_FULL'
]

random.seed(config['seed'])

class my_queue:
    def __init__(self, maxsize: int, result: List[str]) -> None:
        self.q = []
        self.maxsize = maxsize
        self.result = result

    def push(self, n: int) -> None:
        if len(self.q) < self.maxsize:
            self.q.insert(0, n)
        else:
            self.result.append('Full')
    
    def pop(self) -> None:
        if self.q:
            self.q.pop()
        else:
            self.result.append('Empty')
    
    def front(self) -> None:
        if self.q:
            self.result.append(self.q[-1])
        else:
            self.result.append('')
    
    def display(self) -> None:
        if self.q:
            result_str = [str(e) for e in self.q]
            self.result.append(" ".join(result_str))
        else:
            self.result.append('')
    
    def check(self) -> None:
        self.result.append(str(len(self.q)))
    
    def empty(self) -> None:
        if self.q:
            self.result.append('False')
        else:
            self.result.append('True')
    
    def full(self) -> None:
        if len(self.q) >= self.maxsize:
            self.result.append('True')
        else:
            self.result.append('False')

    def get_result(self) -> List[str]:
        return self.result


def gen() -> Tuple[List[str], List[str]]:
    testcase_input = []
    testcase_output = []

    num_cmd = random.randint(config['cmd_lower'], config['cmd_upper'])
    cmd_weights = [
        config['prob_push'],
        config['prob_pop'],
        config['prob_front'],
        config['prob_display'],
        config['prob_check'],
        config['prob_is_empty'],
        config['prob_is_full']
    ]
    testcase_input.append(str(num_cmd))
    
    queue_maxsize = random.randint(config['size_lower'], config['size_upper'])
    testcase_input.append(str(queue_maxsize))
    q = my_queue(queue_maxsize, testcase_output)
    for _ in range(num_cmd):
        cmd = random.choices(cmd_list, weights=cmd_weights)[0]
        if cmd == cmd_list[0]:
            n = random.randint(config['value_lower'], config['value_upper'])
            cmd = cmd + f' {n}'
            q.push(n)
        elif cmd == cmd_list[1]:
            q.pop()
        elif cmd == cmd_list[2]:
            q.front()
        elif cmd == cmd_list[3]:
            q.display()
        elif cmd == cmd_list[4]:
            q.check()
        elif cmd == cmd_list[5]:
            q.empty()
        elif cmd == cmd_list[6]:
            q.full()
        else:
            print(f'{bcolors.FAIL}Unknown command{bcolors.ENDC}')

        testcase_input.append(cmd)

    return testcase_input, q.get_result()
        

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