if __name__ == '__main__':
    line1 = list(map(float, input().split(' ')))
    line2 = list(map(float, input().split(' ')))
    dict1, dict2, dict3, output1 = {}, {}, {}, {}
    for i in range(int(line1[0])):
        dict1[line1[2 * i + 1]] = line1[2 * i + 2]
    for j in range(int(line2[0])):
        dict2[line2[2 * j + 1]] = line2[2 * j + 2]
    for k, v in dict1.items():
        for ke, va in dict2.items():
            if ke + k in dict3.keys():
                dict3[ke + k] += va * v
            else:
                dict3[ke + k] = va * v
    output = dict(sorted(dict3.items(), key=lambda x: x[0], reverse=True))
    for a, b in output.items():
        if (b != 0):
            output1[a] = b
    print(len(output1), end='')
    for a, b in output1.items():
        print(' ', end='')
        print(int(a), end=' ')
        print('%.1f' % b, end='')
