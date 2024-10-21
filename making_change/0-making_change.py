#!/usr/bin/python3

"""
determine the fewest number of coins needed
to meet a given amount total
"""


def makeChange(coins, total):

    if total == 0:
        return 0

    # Initialize dp array a large number (infini), except dp[0] which is 0
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    # Iterate over each coin and update the dp array
    for coin in coins:
        for i in range(coin, total + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)

    # If dp[total] is still inf, then it's not possible to make that total
    return dp[total] if dp[total] != float('inf') else -1
