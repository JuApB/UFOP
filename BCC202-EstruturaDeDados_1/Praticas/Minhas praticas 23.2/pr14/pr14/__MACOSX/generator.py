import random
import numpy as np
import subprocess
import csv

def get_strings():
    strings = []
    with open('string-norm.txt') as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        for row in csv_reader:
            strings.append(row[0])
    return strings

def create_test_case(cases, strings):
    strings = np.random.permutation(strings)
    lines = [f'{cases}\n']
    print(f'{cases} Gerando casos')
    for _ in range(cases):
        m = random.randint(8, 5000)
        p = random.randint(1, 100)
        lines.append(f'{m} {p} ')
        for _ in range(p):
            lines.append(f'{random.randint(1, 100)} ')
        c = random.randint(5, m - 1)
        lines.append(f'\n{c} ')
        for i in np.random.permutation(range(c)):
            lines.append(f'{strings[i%len(strings)]} ')
        lines.append(f'\n')
    
    print(f'{cases} Escrevendo entrada')
    with open(f'{cases}.in', 'w') as f:
        f.writelines(lines)

    print(f'{cases} Escrevendo saida\n')
    subprocess1 = subprocess.Popen(f'./solucao < {cases}.in', shell=True, stdout=subprocess.PIPE)
    with open(f'{cases}.out', 'w') as f:
        f.writelines(subprocess1.stdout.read().decode('utf-8'))

number_of_cases = [5, 10, 25, 50, 100, 250, 500, 750, 1000]
strings = get_strings()
for c in number_of_cases:
    create_test_case(c, strings)
