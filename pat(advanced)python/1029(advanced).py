if __name__ == '__main__':
    line1 = list(map(int,input().split()))
    line2 = list(map(int,input().split()))
    number_line1 = line1[0]
    number_line2 = line2[0]
    number_all = number_line1+number_line2
    line = line1[1:]+line2[1:]
    line.sort()
    if(number_all%2==0):
        print(line[int(number_all/2-1)])
    else:
        print(line[int((number_all-1)/2)])

