#!/usr/bin/env python3


"""write a method that calculates
the fewest number of operations needed to result in exactly"""


def minOperations(n):
    """ execute only two operations in this file """

    if n <= 1:

        return 0

    operations = 0
    number = 2

    while number <= n:
        if n % number == 0:
            operations += number
            n //= number
        else:
            number += 1

    return operations
