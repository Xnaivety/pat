def is_prime(number):
    if (number == 1):
        return False
    elif (number == 2):
        return True
    else:
        for i in range(3, int(number ** 0.5) + 1, 1):
            if (number % i == 0):
                return False
        return True


def reverse_number(number, base):
    ans = ''
    while (number != 0):
        remain = number % base
        number = number // base
        ans = ans + str(remain)
    return int(ans, base)


if __name__ == '__main__':
    index = list(map(int, input().split()))
    while (index[0] >= 0):
        number = index[0]
        base = index[1]
        if (is_prime(number) and is_prime(reverse_number(number, base))):
            print('Yes')
        else:
            print('No')
        index = list(map(int, input().split()))
