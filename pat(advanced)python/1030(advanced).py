import copy


def dfs(city, distance, cost):
    global final_path, final_cost, final_distance
    # 不满足下列条件的，进行返回
    if distance > mindis[city] or (distance == mindis[city] and cost > mincost[city]):
        return
    # 进入这个城市
    path.append(city)
    if (city == destination):  # 到达目的地
        final_cost = cost
        final_distance = distance
        mindis[city] = distance
        mincost[city] = cost
        final_path = copy.deepcopy(path)
    else:  # 未到达目的地
        mindis[city] = distance
        mincost[city] = cost
        for i in cities[city]:
            dfs(i, distance + distance_tables[city][i], cost + cost_tables[city][i])
    path.pop()


if __name__ == '__main__':
    number_cities, number_highways, start_city, destination = list(map(int, input().split()))
    distance_tables = [[None for i in range(number_cities)] for x in range(number_cities)]
    cost_tables = copy.deepcopy(distance_tables)
    cities = [[] for x in range(number_cities)]
    for i in range(number_highways):
        index_city1, index_city2, index_distance, index_cost = list(map(int, input().split()))
        distance_tables[index_city1][index_city2] = distance_tables[index_city2][index_city1] = index_distance
        cost_tables[index_city1][index_city2] = cost_tables[index_city2][index_city1] = index_cost
        cities[index_city1].append(index_city2)
        cities[index_city2].append(index_city1)
    # 数据录入完成
mindis = [99999 for i in range(number_cities)]
mincost = copy.deepcopy(mindis)
final_distance = None
final_cost = None
path = []
final_path = []
dfs(start_city, 0, 0)
for i in final_path:
    print(i, end=' ')
print(final_distance, end=' ')
print(final_cost)
