if __name__ == '__main__':
    line1 = {}
    line2 = {}
    a = input().split(' ')
    for i in range(int(a[0])):
        line1[int(a[1 + 2 * i])] = a[2 + 2 * i]
    b = input().split(' ')
    for j in range(int(b[0])):
        line2[int(b[1 + 2 * j])] = b[2 + 2 * j]
    c = list(set(list(line1) + list(line2)))  # set函数目的为了去重
    output = {}
    for m in c:
        if m in line1.keys():
            if m in line2.keys():  # AB中都有
                output[m] = float(line2[m]) + float(line1[m])
            else:  # 只在a中
                output[m] = float(line1[m])
        else:  # 只在b中
            output[m] = float(line2[m])
    d = sorted(c, key=lambda x: x, reverse=True)
    count = 0
    outstring = ''
    for g in d:
        if output[g] != 0:
            outstring += ' ' + str(g) + ' ' + "{:.1f}".format(output[g])
            count += 1
    print(count, end='')
    print(outstring)


