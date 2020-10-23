def dfs(node):
    global cnt
    global total_time
    global index_ganger, index_ganger_time
    if visited[node] == 1:
        return
    visited[node] = 1
    cnt += 1
    this_node_time = 0
    for i in tables[node]:
        this_node_time += time_tables[node][i]
    if this_node_time > index_ganger_time:
        index_ganger_time = this_node_time
        index_ganger = node
    for i in tables[node]:
        dfs(i)
    total_time += this_node_time


if __name__ == '__main__':
    line = list(map(int, input().split()))
    num_phone_call = line[0]
    limit_time = line[1]
    phone_list = [[] for x in range(num_phone_call)]
    people_dict = {}
    people_dict1 = {}
    count = -1
    tables = [[] for x in range(2000)]
    time_tables = [[0 for x in range(2000)] for k in range(2000)]
    for i in range(num_phone_call):
        line1 = input().split()
        phone_list[i] = line1[0], line1[1], line1[2]
        if line1[0] not in people_dict.keys():
            count += 1
            people_dict[line1[0]] = count
            people_dict1[count] = line1[0]
        if line1[1] not in people_dict.keys():
            count += 1
            people_dict[line1[1]] = count
            people_dict1[count] = line1[1]
        if people_dict[line1[1]] not in tables[people_dict[line1[0]]]:
            tables[people_dict[line1[0]]].append(people_dict[line1[1]])
            tables[people_dict[line1[1]]].append(people_dict[line1[0]])
        time_tables[people_dict[line1[0]]][people_dict[line1[1]]] += int(line1[2])
        time_tables[people_dict[line1[1]]][people_dict[line1[0]]] += int(line1[2])
    visited = [0 for x in range(count + 1)]
    mark = 0
    ganglist = []
    for i in range(count + 1):
        if visited[i] != 1:
            index_ganger = None
            index_ganger_time = -99999
            gang = []
            mark += 1
            cnt = 0
            total_time = 0
            dfs(i)
            total_time = total_time / 2
            if cnt < 3 or total_time <= limit_time:
                mark -= 1
                continue
            ganglist.append([index_ganger, cnt])

    print(mark)
    for i in ganglist:
        i[0] = people_dict1[i[0]]
    ganglist.sort(key=lambda x: x[0])
    for i in ganglist:
        print(i[0], end=' ')
        print(i[1])
