if __name__ == '__main__':
    number_accounts = int(input())
    number_modified = 0
    final_answer = []
    for i in range(number_accounts):
        line = input().split()
        index_username = line[0]
        index_passwords = line[1]
        index_passwords = index_passwords.replace('1', '@')
        index_passwords = index_passwords.replace('0', '%')
        index_passwords = index_passwords.replace('l', 'L')
        index_passwords = index_passwords.replace('O', 'o')
        if (index_passwords != line[1]):  # 密码没有被修改
            number_modified += 1
            final_answer.append((index_username, index_passwords))
    if (number_modified == 0):
        if (number_accounts == 1):
            print('There is 1 account and no account is modified')
        else:
            print('There are %d accounts and no account is modified' % number_accounts)
    else:
        print(number_modified)
        for i in final_answer:
            print(i[0], end=' ')
            print(i[1])
