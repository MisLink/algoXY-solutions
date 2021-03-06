import time
import random

HUNDRED_THOUSAND = 100_000
MILLION = 1_000_000


def brute_force(lst):
    i = 0
    while True:
        if i not in lst:
            return i
        i += 1


def main():
    total = 0
    loop_times = 10
    for _ in range(loop_times):
        data = random.sample(
            range(0, HUNDRED_THOUSAND + loop_times), k=HUNDRED_THOUSAND
        )
        start_time = time.perf_counter()
        v = brute_force(data)
        print(f"result: {v}")
        total += time.perf_counter() - start_time
    print(f"Average CPU time: {total / loop_times}s")


if __name__ == "__main__":
    main()
