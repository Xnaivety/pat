def dfs(city):
    mark[city - 1] = 1
    mark1[city - 1] = 1
    for i in tables[city - 1]:
        if i == index_check or mark1[i - 1] == 1:
            continue
        dfs(i)
if __name__ == '__main__':
    line = list(map(int, input().split()))
    number_cities = line[0]
    remaining_highways = line[1]
    num_check_cities = line[2]
    tables = [[] for x in range(number_cities)]
    for i in range(remaining_highways):
        index_line = input().split()
        city1 = int(index_line[0])
        city2 = int(index_line[1])
        tables[city1 - 1].append(city2)
        tables[city2 - 1].append(city1)
    checklists = list(map(int, input().split(' ')))
    for j in range(num_check_cities):
        number_repaired_highway = -1
        index_check = checklists[j]
        mark = [0 for x in range(number_cities)]
        for k in range(number_cities): 
            mark1 = [0 for x in range(number_cities)]
            if mark[k] == 0 and index_check != k + 1:
                number_repaired_highway += 1
                dfs(k + 1)
        print(number_repaired_highway)
