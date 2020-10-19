if __name__ == '__main__':
    number = input()
    number1 = str(2*int(number))
    outputstring = 'No'
    if number.count('1')==number1.count('1'):
        if number.count('2')==number1.count('2'):
            if number.count('3') == number1.count('3'):
                if number.count('4') == number1.count('4'):
                    if number.count('5') == number1.count('5'):
                        if number.count('6') == number1.count('6'):
                            if number.count('7') == number1.count('7'):
                                if number.count('8') == number1.count('8'):
                                    if number.count('9') == number1.count('9'):
                                        if number.count('0') == number1.count('0'):
                                            outputstring = 'Yes'
    print(outputstring)
    print(number1)