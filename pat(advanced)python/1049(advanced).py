def count_1(number, length):  # number是字符串
    if length == 1:
        if int(number) >= 1:
            return 1
        else:
            return 0
    else:
        if int(number[0]) == 0:
            return count_1(number[1:], length - 1)
        if int(number[0]) == 1:
            sum1 = int(number[1:]) + 1 + (length - 1) * 10 ** (length - 2) * int(number[0]) + count_1(number[1:], length - 1)
            return sum1
        else:
            sum1 = (length - 1) * 10 ** (length - 2) * int(number[0]) + 10 ** (length - 1) + count_1(number[1:], length - 1)
            return sum1


if __name__ == '__main__':
    line = input()
    length = len(line)
    print(count_1(line, length))
