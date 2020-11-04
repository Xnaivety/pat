def convert(time):
    dd = time[3:5]
    hh = time[6:8]
    mm = time[9:11]
    total = int(dd) * 24 * 60 + int(hh) * 60 + int(mm)
    return total


if __name__ == '__main__':
    dict_records = {}
    rate_list = list(map(int, input().split()))
    number_records = int(input())
    for i in range(number_records):
        line = input().split()
        if line[0] in dict_records.keys():
            dict_records[line[0]].append((line[1], line[2]))
        else:
            dict_records[line[0]] = [(line[1], line[2])]
    for i in range(len(dict_records)):
        minkey = sorted(list(dict_records))[0]
        index_list = sorted(dict_records[minkey], key=lambda x: x[0])
        month = index_list[0][0][:2]
        total_all_money = 0
        outputstr_list = []
        for k in range(len(index_list)):
            if (k < len(index_list) - 1):
                if (index_list[k][1] == 'on-line' and index_list[k + 1][1] == 'off-line'):
                    total_money = 0
                    index_str = ''
                    index_str += str(index_list[k][0][3:])
                    index_str += ' '
                    index_str += str(index_list[k + 1][0][3:])
                    index_str += ' '
                    for i in range(convert(index_list[k][0]), convert(index_list[k + 1][0])):
                        total_money += rate_list[(i % 1440) // 60]
                    total_money /= 100
                    index_str += str(convert(index_list[k + 1][0]) - convert(index_list[k][0]))
                    index_str += ' '
                    index_str += '$%.2f' % total_money
                    total_all_money += total_money
                    outputstr_list.append(index_str)
        if (total_all_money != 0):
            print(minkey, end=' ')
            print('%02s' % month)
            for i in outputstr_list:
                print(i)
            print('Total amount: $%.2f' % total_all_money)
        del dict_records[minkey]
