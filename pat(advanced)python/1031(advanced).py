if __name__ == '__main__':
    words = input()
    length = len(words)
    if(length%3==0):
        for i in range(int(length/3-1)):
            print(words[i],end = '')
            print(' '*int(length/3),end = '')
            print(words[-i-1])
        print(words[int(length/3-1):int(length/3*2)+1])
    elif(length%3==1):
        for i in range(int((length-1)/3)):
            print(words[i],end = '')
            print(' '*int((length-1)/3-1),end = '')
            print(words[-i-1])
        print(words[int((length-1)/3):int((length-1)/3*2+1)])
    elif(length%3==2):
        for i in range(int((length-2)/3)):
            print(words[i],end = '')
            print(' '*int((length-2)/3),end = '')
            print(words[-i-1])
        print(words[int((length-2)/3):int((length-2)/3*2+2)])
