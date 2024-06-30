import os
import random
from config import config
from typing import List, Tuple

class bcolors:
    OKGREEN = '\033[92m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'

cmd_list = [
    'APPEND',
    'INSERT',
    'POP',
    'DISPLAY',
    'REMOVE',
    'CHECK',
    'EMPTY',
    'MIDDLE',
    'REVERSE'
]

random.seed(config['seed'])

class my_linkedlist:
    def __init__(self, result: List[str]) -> None:
        self.ll = []
        self.result = result

    def append(self, n: int) -> None:
        self.ll.append(n)
    
    def insert(self, index: int, n: int) -> None:
        if index < 0 or index > len(self.ll):
            self.result.append('Error')
        else:
            self.ll.insert(index, n)
    
    def pop(self) -> None:
        if len(self.ll) == 0:
            self.result.append('Empty')
        else:
            self.ll = self.ll[:-1]

    def display(self) -> None:
        if self.ll:
            result_str = [str(e) for e in self.ll]
            self.result.append(" ".join(result_str))
        else:
            self.result.append("")

    def remove(self, index: int) -> None:
        if index >= len(self.ll) or index < 0:
            self.result.append('Error')
        else:
            del self.ll[index]
    
    def check(self) -> None:
        self.result.append(str(len(self.ll)))
    
    def empty(self) -> None:
        if self.ll:
            self.result.append('False')
        else:
            self.result.append('True')
    
    def middle(self) -> None:
        if len(self.ll) == 0:
            self.result.append('Empty')
        else:
            index = len(self.ll)
            if index % 2 == 0:
                self.result.append(self.ll[index // 2 - 1])
            else:
                self.result.append(self.ll[index // 2])

    def reverse(self) -> None:
        self.ll.reverse()

    def get_result(self) -> List[str]:
        return self.result


def gen() -> Tuple[List[str], List[str]]:
    testcase_input = []
    testcase_output = []

    num_cmd = random.randint(config['cmd_lower'], config['cmd_upper'])
    cmd_weights = [
        config['prob_append'],
        config['prob_insert'],
        config['prob_pop'],
        config['prob_display'],
        config['prob_remove'],
        config['prob_check'],
        config['prob_empty'],
        config['prob_middle'],
        config['prob_reverse']
    ]
    testcase_input.append(str(num_cmd))
    
    ll = my_linkedlist(testcase_output)
    for _ in range(num_cmd):
        cmd = random.choices(cmd_list, weights=cmd_weights)[0]
        if cmd == cmd_list[0]:
            n = random.randint(config['value_lower'], config['value_upper'])
            cmd = cmd + f' {n}'
            ll.append(n)
        elif cmd == cmd_list[1]:
            index = random.randint(config['cmd_lower'], config['cmd_upper'])
            n = random.randint(config['value_lower'], config['value_upper'])
            cmd = cmd + f' {index} {n}'
            ll.insert(index, n)
        elif cmd == cmd_list[2]:
            ll.pop()
        elif cmd == cmd_list[3]:
            ll.display()
        elif cmd == cmd_list[4]:
            index = random.randint(config['cmd_lower'], config['cmd_upper'])
            cmd = cmd + f' {index}'
            ll.remove(index)
        elif cmd == cmd_list[5]:
            ll.check()
        elif cmd == cmd_list[6]:
            ll.empty()    
        elif cmd == cmd_list[7]:
            ll.middle()
        elif cmd == cmd_list[8]:
            ll.reverse()
        else:
            print(f'{bcolors.FAIL}Unknown command{bcolors.ENDC}')

        testcase_input.append(cmd)

    return testcase_input, ll.get_result()
        

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