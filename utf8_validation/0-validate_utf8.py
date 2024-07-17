#!/usr/bin/python3

"""Write a method that determines
if a given data set represents
a valid UTF-8 encoding"""


def validUTF8(data):
    # Number of bytes in the current UTF-8 character
    n_bytes = 0

    # Masks to check the most significant bits in a byte
    mask1 = 1 << 7
    mask2 = 1 << 6

    # Iterate through each byte in the data
    for num in data:
        mask = 1 << 7
        if n_bytes == 0:
            # Determine the number of bytes in this UTF-8 character
            while mask & num:
                n_bytes += 1
                mask = mask >> 1

            # 1 byte character
            if n_bytes == 0:
                continue

            # If the number of bytes is more than 4 or 1
            # (which should be handled by the continue above)
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            # Check that the byte is a continuation byte
            if not (num & mask1 and not (num & mask2)):
                return False

        n_bytes -= 1

    return n_bytes == 0
