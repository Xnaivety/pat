def convert(number, radix):
    str1 = []
    while (1):
        remainder = number % radix
        Quotient = number // radix
        str1.append(remainder)
        number = Quotient
        if (number == 0):
            break

    str2 = str1.copy()
    str2.reverse()  # 转换后的进制数
    return str1, str2


if __name__ == '__main__':
    line = list(map(int, input().split()))
    number = line[0]
    radix = line[1]
    x, y = convert(number, radix)
    if (x == y):
        print('Yes')
    else:
        print('No')
    count = 0
    for i in y:
        count += 1
        print(i, end='')
        if (count != len(y)):
            print(' ', end='')
