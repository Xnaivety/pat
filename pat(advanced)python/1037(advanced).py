if __name__ == '__main__':
    number_coupon = int(input())
    coupons_list = list(map(int, input().split()))
    number_bonus_products = int(input())
    bonus_products_list = list(map(int, input().split()))

    coupons_list.sort(reverse=True)
    bonus_products_list.sort(reverse=True)
    totalmoney = 0
    for i, j in zip(coupons_list, bonus_products_list):
        if (i > 0 and j > 0):
            totalmoney += i * j
        else:
            break
    coupons_list.reverse()
    bonus_products_list.reverse()
    for i, j in zip(coupons_list, bonus_products_list):
        if (i < 0 and j < 0):
            totalmoney += i * j
        else:
            break
    print(totalmoney)
