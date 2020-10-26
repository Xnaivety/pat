if __name__ == '__main__':
    number_list = input().split()[1:]
    dictone = set()
    ans = set()
    for i in number_list:
        if i not in dictone:
            ans.add(i)
            dictone.add(i)
        elif i in ans:
            ans.remove(i)

if len(ans) == 0:
    print('None')
else:
    for i in number_list:
        if i in ans:
            print(i)
            break
