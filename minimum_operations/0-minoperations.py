#!/usr/bin/env python3


"""write a method that calculates
the fewest number of operations needed to result in exactly"""


def minOperations(n):

    if n <= 1:
        return 0

    operations = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    return operations
