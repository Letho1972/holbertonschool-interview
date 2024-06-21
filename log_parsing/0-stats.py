#!/usr/bin/python3
"""
A script that reads stdin line by line and computes metrics
"""

import sys
from collections import defaultdict


# Tracks the cumulative size of the files
total_file_size = 0

# Stores the counts of different HTTP status codes
status_codes = defaultdict(int)

# Counts the number of processed lines
line_count = 0

# The main loop reads lines from the standard input
try:
    for line in sys.stdin:
        line_count += 1
        parts = line.strip().split()
        if len(parts) < 5:
            continue

        try:
            file_size = int(parts[-1])
            status_code = int(parts[-2])
        except ValueError:
            continue

        total_file_size += file_size
        status_codes[status_code] += 1

        if line_count % 10 == 0 or line_count == 1:
            print(f"File size: {total_file_size}")
            for code in sorted(status_codes):
                if status_codes[code] > 0:
                    print(f"{code}: {status_codes[code]}")

except KeyboardInterrupt:
    print(f"File size: {total_file_size}")
    for code in sorted(status_codes):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")
    sys.exit(0)
