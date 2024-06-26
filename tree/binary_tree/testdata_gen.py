import os
import random
import queue
from config import config
from typing import List, Tuple

class bcolors:
    OKGREEN = '\033[92m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'

cmd_list = [
    'PREORDER',
    'INORDER',
    'POSTORDER',
    'LEVELORDER'
]

random.seed(config['seed'])

class Node:
    def __init__(self, data: int) -> None:
        self.data = data
        self.left = None
        self.right = None


class my_binary_tree:
    def __init__(self, data: List[int]) -> None:
        self.root = Node(0)
        self.data = data
        self.construct_level_order_tree()

    def construct_level_order_tree(self) -> None:
        q = queue.Queue()
        self.root.data = self.data[0]
        q.put(self.root)

        turn_left = True
        for i in range(1, len(self.data)):
            node = Node(self.data[i])
            q.put(node)

            if turn_left:
                cur = q.get()
                cur.left = node
                turn_left = False
            else:
                cur.right = node
                turn_left = True

    def preorder_traversal(self, node: Node, result: List[int]) -> None:
        if node:
            result.append(node.data)
            self.preorder_traversal(node.left, result)
            self.preorder_traversal(node.right, result)

    def inorder_traversal(self, node: Node, result: List[int]) -> None:
        if node:
            self.preorder_traversal(node.left, result)
            result.append(node.data)
            self.preorder_traversal(node.right, result)

    def postorder_traversal(self, node: Node, result: List[int]) -> None:
        if node:
            self.preorder_traversal(node.left, result)
            self.preorder_traversal(node.right, result)
            result.append(node.data)
            
    def levelorder_traversal(self, result: List[int]) -> None:
        q = queue.Queue()
        q.put(self.root)

        while not q.empty():
            cur = q.get()
            result.append(cur.data)

            if cur.left:
                q.put(cur.left)
            
            if cur.right:
                q.put(cur.right)


def gen() -> Tuple[List[str], List[str]]:
    testcase_input = []
    testcase_output = []

    num_node = random.randint(config['node_lower'], config['node_upper'])
    testcase_input.append(str(num_node))
    node_data = [str(random.randint(config['value_lower'], config['value_upper'])) for _ in range(num_node)]
    testcase_input.append(" ".join(node_data))

    num_cmd = random.randint(config['cmd_lower'], config['cmd_upper'])
    cmd_weights = [
        config['prob_preorder'],
        config['prob_inorder'],
        config['prob_postorder'],
        config['prob_levelorder']
    ]
    testcase_input.append(str(num_cmd))
    
    bt = my_binary_tree(node_data)
    for _ in range(num_cmd):
        cmd = random.choices(cmd_list, weights=cmd_weights)[0]
        testcase_input.append(cmd)
        temp = []
        if cmd == cmd_list[0]:
            bt.preorder_traversal(bt.root, temp)
            temp = [str(e) for e in temp]
            testcase_output.append(" ".join(temp))
        elif cmd == cmd_list[1]:
            bt.inorder_traversal(bt.root, temp)
            temp = [str(e) for e in temp]
            testcase_output.append(" ".join(temp))
        elif cmd == cmd_list[2]:
            bt.postorder_traversal(bt.root, temp)
            temp = [str(e) for e in temp]
            testcase_output.append(" ".join(temp))
        elif cmd == cmd_list[3]:
            bt.levelorder_traversal(temp)
            temp = [str(e) for e in temp]
            testcase_output.append(" ".join(temp))
        else:
            print(f'{bcolors.FAIL}Unknown command{bcolors.ENDC}')

    return testcase_input, testcase_output
        

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