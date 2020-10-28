if __name__ == '__main__':
    line = list(map(int, input().split()))
    number_exits = line[0]
    exits_list = line[1:]
    tables = [0]
    total = 0
    for i in range(0, number_exits - 1):
        total += exits_list[i]
        tables.append(total)
    total += exits_list[-1]
    for i in range(int(input())):
        indexexit1, indexexit2 = list(map(int, input().split()))
        indexexit2 -= 1
        indexexit1 -= 1
        if indexexit1 > indexexit2:
            indexexit1, indexexit2 = indexexit2, indexexit1
        distance = tables[indexexit2] - tables[indexexit1]
        print(min([distance, total - distance]))
