import time
import random

HUNDRED_THOUSAND = 100_000
MILLION = 1_000_000


def min_free(lst):
    n = len(lst)
    flags = [False for i in range(n + 1)]
    for i in lst:
        if i < n:
            flags[i] = True
    for i, f in enumerate(flags):
        if f is False:
            return i


def main():
    total = 0
    loop_times = 10
    for _ in range(loop_times):
        data = random.sample(range(0, MILLION + loop_times), k=MILLION)
        start_time = time.clock()
        v = min_free(data)
        print(f"result: {v}")
        total += time.clock() - start_time
    print(f"Average CPU time: {total / loop_times}s")


if __name__ == "__main__":
    main()
