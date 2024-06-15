import os
import time
import shutil
import subprocess
from resource import getrusage, RUSAGE_CHILDREN 
from config import config

class bcolors:
    OKGREEN = '\033[92m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'


def compare():
    num_testcase = config['num_testcase']
    exec_files = ['stack_cpp.out']
    testcase_input = './input'
    output_folder = './output'
    golden_output_folder = './golden_output'

    for exec_file in exec_files:
        runtimes = []
        memories = []
        os.makedirs(output_folder, exist_ok=True)
        for i in range(num_testcase):
            start_time = time.time()
            p = subprocess.Popen(f'./{exec_file} < {testcase_input}/{i}.in > {output_folder}/{i}.out', shell=True)
            p.wait()
            end_time = time.time()
            memories.append(getrusage(RUSAGE_CHILDREN).ru_maxrss / 10**6 * 1024)
            runtimes.append(round((end_time - start_time) * 1000))
        
        print('\n{:^10s}{:^10s}{:^10s}'.format('Testcase', 'Result', 'Runtime'))
        print('=' * 30)

        wa_count = 0
        results = []
        for i in range(num_testcase):
            with open(f'{golden_output_folder}/{i}.out', 'r') as f:
                ans_gt = f.read().splitlines()
                ans_gt = [e.strip() for e in ans_gt]

            with open(f'{output_folder}/{i}.out', 'r') as f:
                ans = f.read().splitlines()
                ans = [e.strip() for e in ans]

            if ans != ans_gt:
                result = f'{bcolors.FAIL}WA{bcolors.ENDC}'
                wa_count += 1
            else:
                result = f'{bcolors.OKGREEN}AC{bcolors.ENDC}'

            results.append(result)
            print('{:^10s}{:^10s}{:^10s}'.format('#' + str(i), result, str(runtimes[i]) + 'ms'))

        print('\n========={:^10s}========='.format('Result'))
        print('{:<9s}:   {:>3s} %'.format('AC Rate', str(round((1 - wa_count / num_testcase) * 100))))
        print('{:<9s}:   {:>3s} ms'.format('Runtime', str(round(sum(runtimes) / num_testcase))))
        print('{:<9s}:   {:>3s} KB'.format('Memory', str(round(sum(memories) / num_testcase))))
        print('\n')

        shutil.rmtree(output_folder)


if __name__ == '__main__':
    compare()