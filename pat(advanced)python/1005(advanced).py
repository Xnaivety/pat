if __name__ == '__main__':
    output = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten']
    line1 = input()
    sum1 = 0
    for i in line1:
        sum1 += int(i)
    flag = 0
    for i in str(sum1):
        if flag != 0:
            print(' ', end='')
        flag += 1
        print(output[int(i)], end='')
