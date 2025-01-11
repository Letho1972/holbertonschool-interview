#!/usr/bin/python3
""" Prime Game """


def isWinner(x, nums):
    """ Maria and Ben are playing a game """
    if not nums or x < 1:
        return None
    n = max(nums)
    K = [True for _ in range(max(n + 1, 2))]
    for i in range(2, int(n**0.5) + 1):
        if not K[i]:
            continue
        for j in range(i*i, n + 1, i):
            K[j] = False

    K[0] = K[1] = False
    c = 0
    for i in range(len(K)):
        if K[i]:
            c += 1
        K[i] = c

    P = 0
    for n in nums:
        P += K[n] % 2 == 1
    if P * 2 == len(nums):
        return None
    if P * 2 > len(nums):
        return "Maria"
    return "Ben"
