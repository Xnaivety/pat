if __name__ == '__main__':
    input1 = int(input())
    list1, list2, list3 = [], [], []
    for i in range(input1):
        index = input().split()
        list1.append(index[0])
        list2.append(index[1])
        list3.append(index[2])
    signin = dict(zip(list1, list2))
    signout = dict(zip(list1, list3))
    print(sorted(signin.items(), key=lambda a: a[1], reverse=False)[0][0], end=' ')
    print(sorted(signout.items(), key=lambda b: b[1], reverse=True)[0][0])
