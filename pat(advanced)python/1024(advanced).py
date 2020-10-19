def palindromic(number):
    number1 = int(str(number)[-1::-1])
    number += number1
    return number


if __name__ == '__main__':
    line = list(map(int, input().split()))
    number = line[0]
    max_steps = line[1]
    steps = 0
    if str(number) == str(number)[-1::-1]:
        print(number)
        print(steps)
    else:
        for i in range(max_steps):
            number = palindromic(number)
            steps += 1
            if str(number) == str(number)[-1::-1]:
                break
        print(number)
        print(steps)
