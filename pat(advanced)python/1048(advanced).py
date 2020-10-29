if __name__ == '__main__':
    number_coins, need_pay = list(map(int, input().split()))
    coin_dict = {}
    for i in input().split():
        if int(i) in coin_dict.keys():
            coin_dict[int(i)] += 1
        else:
            coin_dict[int(i)] = 1
    flag = 0
    for i in range(1, need_pay + 1):
        if i in coin_dict.keys() and need_pay - i in coin_dict.keys():
            if i == need_pay - i and coin_dict[i] > 1:
                flag = 1
                print(i, need_pay - i)
                break
            elif i != need_pay - i:
                flag = 1
                print(i, need_pay - i)
                break
    if flag != 1:
        print('No Solution')
