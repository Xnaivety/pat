if __name__ == '__main__':
    stringinput = input()
    longest = 1
    for i in range(len(stringinput)):
        length = 1
        indexlength = 1
        try:
            while (stringinput[i - indexlength] == stringinput[i + indexlength]):
                length += 2
                if (longest < length):
                    longest = length
                indexlength += 1
        except:
            continue
    for i in range(len(stringinput)):
        length = 0
        indexlength = 0
        try:
            while (stringinput[i - indexlength] == stringinput[i + 1 + indexlength]):
                length += 2
                if (longest < length):
                    longest = length
                indexlength += 1
        except:
            continue
    print(longest)
