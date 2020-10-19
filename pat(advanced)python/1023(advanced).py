if __name__ == '__main__':
    number = input()
    number1 = str(2*int(number))
    count = 0
    stringcheck = '1234567890'
    for i in stringcheck:
        if number.count(i)==number1.count(i):
            count += 1
    if count==10:
        print('Yes')
    else:
        print('No')
    print(number1)