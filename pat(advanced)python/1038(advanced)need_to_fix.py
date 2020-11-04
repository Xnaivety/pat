if __name__ == '__main__':
    line = input().split()
    number_numbers = int(line[0])
    number_list = line[1:]
    for i in range(number_numbers - 1):
        for j in range(number_numbers - 1):
            if (number_list[j] + number_list[j + 1] > number_list[j + 1] + number_list[j]):
                number_list[j], number_list[j + 1] = number_list[j + 1], number_list[j]
    output = ''.join(number_list)
    count = 0
    if (int(output) == 0):
        print('0')
    else:
        for i in output:
            if (i == '0' and count == 0):
                continue
            else:
                count = 1
            print(i, end='')
