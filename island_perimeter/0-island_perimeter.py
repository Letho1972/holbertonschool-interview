#!/usr/bin/python3
"""
Module that calculates the perimeter of an island in a grid.

The grid is a 2D list where:
- 0 represents water
- 1 represents land

An island is a group of 1's (land) connected either vertically or horizontally.
The perimeter of the island is defined as the total length of its boundary.
"""


def island_perimeter(grid):
    """Function that calculates the perimeter of an island in a grid."""
    result = 0
    for i in range(len(grid)):  # Iterate through each row of the grid
        for j in range(len(grid[i])):  # Iterate through each column
            if grid[i][j] == 1:  # Check if the current cell is land
                result += 4  # Add 4 for the potential edges of this land cell

                # Check for a neighboring land cell above
                if i - 1 >= 0 and grid[i - 1][j] == 1:
                    result -= 2  # Subtract 2 because the edge is shared

                # Check for a neighboring land cell to the left
                if j - 1 >= 0 and grid[i][j - 1] == 1:
                    result -= 2  # Subtract 2 because the edge is shared

    return result  # Return the total perimeter calculated
