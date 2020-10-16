if __name__ == '__main__':
    line1 = int(input())
    line2 = [0] + list(map(int, input().split()))
    sumlist = [0]
    index = 0
    negativeflag = 0
    maxvalue = -999999
    maxlength = -1
    for i in range(line1):
        if line2[i + 1] >= 0:
            negativeflag = 1
        index += line2[i + 1]
        sumlist.append(index)
    minlist = []
    minsum = 999999
    minsumflag = 0
    minsumflaglist = []
    for i in range(line1 + 1):
        if sumlist[i] < minsum:
            minsum = sumlist[i]
            minsumflag = i
        minlist.append(minsum)
        minsumflaglist.append(minsumflag)
    for i in range(1, line1 + 1):
        if (sumlist[i] - minlist[i]) > maxvalue:
            cursor1 = minsumflaglist[i]
            cursor2 = i
            maxvalue = sumlist[i] - minlist[i]
            maxlength = cursor2 - cursor1 + 1
        elif (sumlist[i] - minlist[i]) == maxvalue and i - minsumflaglist[i] + 1 > maxlength:
            cursor1 = minsumflaglist[i]
            cursor2 = i
            maxvalue = sumlist[i] - minlist[i]
            maxlength = cursor2 - cursor1 + 1
    if negativeflag == 0:
        print('0', end=' ')
        print(line2[1], end=' ')
        print(line2[-1])
    else:
        print(maxvalue, end=' ')
        print(line2[cursor1 + 1], end=' ')
        print(line2[cursor2])
