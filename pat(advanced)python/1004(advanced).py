if __name__ == '__main__':
    adjacency, this_queue, output = {}, [1], []
    for i in range(int(input().split()[1])):
        line = list(map(int, input().split()))  # split函数内将str参数设为' ',会造成第四个测试点非零返回，str不设参数，默认为' '
        adjacency[line[0]] = line[2:]
    while this_queue:
        next_queue, p = [], 0
        for t in this_queue:
            try:
                next_queue += adjacency[t]
            except:
                p += 1
        output.append(p)
        this_queue = next_queue
    print(' '.join(map(str, output)))  # join函数将字符串列表链接
