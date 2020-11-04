if __name__ == '__main__':
    line1 = input().split(' ', 1)
    num = int(line1[0]) - 1
    floors = line1[1].split()
    temptail = 1
    sumtime = 0
    sumtime += int(floors[0]) * 6
    for i in range(num):
        cursor1 = int(floors[temptail - 1])
        cursor2 = int(floors[temptail])
        if (cursor2 > cursor1):
            sumtime += 6 * (cursor2 - cursor1)
        elif (cursor2 < cursor1):
            sumtime += 4 * (cursor1 - cursor2)
        temptail += 1
    sumtime += (num + 1) * 5
    print(sumtime)
