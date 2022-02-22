import sys
import time
n_exp = 5

for i in range(0, n_exp+1):
    n = 10**i
    start = time.perf_counter_ns()
    test_m = dict()
    for j in range(n):
        test_m[j] = j
    stop = time.perf_counter_ns()
    print(sys.getsizeof(test_m), stop-start)

