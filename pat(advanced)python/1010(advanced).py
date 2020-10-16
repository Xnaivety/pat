def convert(s, radix):
    t = 0
    point = 0
    for x in range(len(s)):
        t += int(s[-x-1], 36) * (radix ** point)
        point += 1
    return t
def find(target,n):
    low = max([ int(x, 36) for x in n]) + 1
    high = target+1
    while(low <= high):
        rad = round((low + high) / 2)
        t= convert(n, rad)
        if t == target:
            return rad
        else:
            if t > target:
                high = rad - 1
            else:
                low = rad + 1
    return 'Impossible'
if __name__ == "__main__":
    line=input().split(" ")
    n1 = line[0]
    n2 = line[1]
    tag = int(line[2])
    radix = int(line[3])
    if tag == 1:
        t = convert(n1, radix)
        print(find(t, n2))
    else:
        t=convert(n2, radix)
        print(find(t, n1))