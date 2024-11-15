#!/usr/bin/python3
"""
    Module that calculates the perimeter of an island in a grid
    The grid is a 2D list where:
- 0 represents water
- 1 represents land

An island is a group of 1's (land) connected either vertically or horizontally.
The perimeter of the island is defined as the total length of its boundary.
"""


def island_perimeter(grid):
    """Function that calculates the perimeter of an island in a grid
       grid (list of list of int): A 2D list representing the grid, where
       0 represents water and 1 represents land.
    """
    result = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                result += 4
                if i - 1 >= 0 and grid[i - 1][j] == 1:
                    result -= 2
                if j - 1 >= 0 and grid[i][j - 1] == 1:
                    result -= 2

    return result
