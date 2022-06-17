from random import randint
import os
import sys
import time

def CRC(string:str) -> int:
    h = 0
    for ki in string:
        highorder = h & 0xf8000000
        h = (h << 5) & 0xffffffff
        h = h ^ (highorder >> 27)
        h = h ^ ord(ki)
    return h


def PJW(string:str) -> int:
    h = 0
    for ki in string:
        h = (h << 4) + ord(ki)
        g = h & 0xf0000000
        if (g != 0):
            h = h ^ (g >> 24)
            h = h ^ g
    return h

def BUZ(string:str) -> int:
    R = {chr(i): randint(0,255) for i in range(0, 255)}
    h = 0
    for ki in string:
        highorder = h & 0x80000000
        h = (h << 1) & 0xffffffff
        h = h ^ (highorder >> 31)
        h = h ^ R[ki]

def data_from_file(filename):
    reader = open(filename, 'r')
    data = reader.read().strip()
    data = data.strip('\n')
    reader.close()
    return data

def find_duplicates(files: list[str], hash_function: callable) -> dict[str, list[str]]:
    cache = dict()
    for file in files:
        cache[file] = hash_function(data_from_file(file))
    
    duplicates = dict()
    
    for i in range(len(files)):
        duplicates[files[i]] = []
        for j in range(i+1,len(files)):
            if cache[files[i]] == cache[files[j]]:
                duplicates[files[i]].append(files[j])
    
    return duplicates


if __name__ == '__main__':
    HASH_FUNCTIONS = {'CRC': CRC, 'PJW': PJW, 'BUZ':BUZ, 'hash': hash}
    
    dir_path = sys.argv[1]
    #hash_type = sys.argv[2]
    
    os.chdir(dir_path)
    for h in HASH_FUNCTIONS:
        print('-----------------')
        print(f"hash type - {h}")
        start = time.perf_counter_ns()
        ans = find_duplicates(os.listdir(), HASH_FUNCTIONS[h])
        stop = time.perf_counter_ns()
        ch = 0
        for key in ans:
            if ans[key]:
                ch += 1
        print(f'dublicates - {ch}')
        print(f'time - {(stop-start)*10**-9}')
        print('-----------------')
