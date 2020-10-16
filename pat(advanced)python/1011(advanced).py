if __name__ == '__main__':
    list1 = ['W', 'T', 'L']
    line1 = list(map(float, input().split()))
    line2 = list(map(float, input().split()))
    line3 = list(map(float, input().split()))
    dict1 = dict(zip(line1, list1))
    dict2 = dict(zip(line2, list1))
    dict3 = dict(zip(line3, list1))
    print(dict1[max(line1)], end=' ')
    print(dict2[max(line2)], end=' ')
    print(dict3[max(line3)], end=' ')
    maximum = (max(line1) * max(line2) * max(line3) * 0.65 - 1) * 2
    print('%.2f' % maximum)
