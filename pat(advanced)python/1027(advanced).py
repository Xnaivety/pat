def convert(number):
    holika = []
    if(number==0):
        print('00',end = '')
        return
    while(number!=0):
        quotient = number//13
        remainder = number%13
        number = quotient
        holika.append(remainder)
    holika.reverse()
    holika = list(map(str,holika))
    count = -1
    for i in holika:
        count += 1
        if(int(i)>=10):
            if(i=='10'):
                holika[count] = 'A'
            elif(i=='11'):
                holika[count] = 'B'
            elif(i=='12'):
                holika[count] = 'C'
    output = ''.join(holika)
    if(len(output)==1):
        print('0%s'%output,end = '')
    else:
        print(output,end = '')

if __name__ == '__main__':
    line = list(map(int,input().split()))
    print("#", end='')
    for i in line:
        convert(i)


