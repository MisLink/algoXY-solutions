import time
import random

HUNDRED_THOUSAND = 100_000
MILLION = 1_000_000


def min_free(lst, l, u):
    m = (l + u) // 2
    if not lst:
        return l
    left = list(filter(lambda x: x <= m, lst))
    right = list(filter(lambda x: x > m, lst))
    if len(left) == m - l + 1:
        return min_free(right, m + 1, u)
    else:
        return min_free(left, l, m)


def min_free_(lst):
    l = 0
    u = len(lst) - 1
    while len(lst) > 0:
        m = (l + u) // 2
        left = 0
        right = 0
        for right, item in enumerate(lst):
            if item <= m:
                lst[left], lst[right] = lst[right], lst[left]
                left += 1
        if left == m - l + 1:
            lst = lst[left:]
            l = m + 1
        else:
            lst = lst[:left]
            u = m
    return l


def main():
    total = 0
    loop_times = 10
    for i in range(loop_times):
        data = random.sample(range(0, MILLION + loop_times), k=MILLION)
        start_time = time.clock()
        v1 = min_free(data, 0, len(data) - 1)
        v2 = min_free_(data)
        print(f'result 1: {v1}')
        print(f'result 2: {v2}')
        total += time.clock() - start_time
    print(f'Average CPU time: {total / loop_times}s')


if __name__ == '__main__':
    main()
