#!/usr/bin/python3
import sys

"""Write a program that solves the N queens problem."""


def print_usage_and_exit(message, status):
    print(message)
    sys.exit(status)


def is_valid(board, row, col):
    # verify if queen is on board row and col
    for i in range(row):
        if board[i] == col or\
                board[i] - i == col - row or\
                board[i] + i == col + row:
            return False

    return True


def solve_nqueen(N, row, board, solutions):
    #
    if row == N:
        solutions.append(board[:])
        return
    for col in range(N):
        if is_valid(board, row, col):
            board[row] = col
            solve_nqueen(N, row + 1, board, solutions)


def main():
    if len(sys.argv) != 2:
        print_usage_and_exit("Usage: nqueens N", 1)

    try:
        N = int(sys.argv[1])

    except ValueError:
        print_usage_and_exit("N must be a number", 1)

    if N < 4:
        print_usage_and_exit("N must be at least 4", 1)

    solutions = []
    board = [-1] * N
    solve_nqueen(N, 0, board, solutions)

    for solution in solutions:
        print([[i, solution[i]] for i in range(N)])


if __name__ == "__main__":
    main()
