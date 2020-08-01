def djkstra(indexcity):
    while (indexcity != endcity):
        for i in range(number_citys):
            if (distance_of_two_roads[indexcity][i] != 999999 and visit[i] == 0):
                if (mindis[i] > mindis[indexcity] + distance_of_two_roads[indexcity][i]):
                    mindis[i] = mindis[indexcity] + distance_of_two_roads[indexcity][i]
                    number_count[i] = number_count[indexcity]
                    rescue_count[i] = rescue_count[indexcity] + number_rescue_teams[i]
                elif (mindis[i] == mindis[indexcity] + distance_of_two_roads[indexcity][i]):
                    number_count[i] += number_count[indexcity]
                    if(rescue_count[i]<rescue_count[indexcity]+number_rescue_teams[i]):
                        rescue_count[i] = rescue_count[indexcity] + number_rescue_teams[i]
        small = sorted(mindis[i] for i in range(number_citys) if visit[i] == 0)[0]
        x = sorted(i for i in range(number_citys) if mindis[i] == small and visit[i] == 0)[0]
        visit[x] = 1
        indexcity = x


# djkstra算法用数组保存每个结点的邻接表提高运行效率
if __name__ == "__main__":
    # 获取第一行数据
    line1 = input().split(' ')
    number_citys = int(line1[0])
    number_roads = int(line1[1])
    startcity = int(line1[2])
    endcity = int(line1[3])
    # 获取第二行数据
    number_rescue_teamss = input().split(' ')
    number_rescue_teams = [int(x) for x in number_rescue_teamss]
    distance_of_two_roads = [[999999 for i in range(number_citys)] for k in range(number_citys)]  # 999999代表两个城市不通
    # 获取后面的数组
    for i in range(number_roads):
        line = input().split(' ')
        distance_of_two_roads[int(line[0])][int(line[1])] = int(line[2])
        distance_of_two_roads[int(line[1])][int(line[0])] = int(line[2])

    # 需要维护的参数数组的创建
    mindis = [999999 for i in range(number_citys)]  # 初始化mindis数组，该数组记录到每个城市的最短路径
    number_count = [0 for i in range(number_citys)]  # 初始化number_count数组，该数组记录到每个城市最短路径的数量
    rescue_count = [0 for i in range(number_citys)]  # 初始化rescue_count数组，该数组记录到每个城市最短路径下，最多救援队的个数
    visit = [0 for i in range(number_citys)]
    # 城市出发点在startcity，因此手动初始化startcity的所有参数
    visit[startcity] = 1
    number_count[startcity] = 1
    rescue_count[startcity] = number_rescue_teams[startcity]
    mindis[startcity] = 0
    # 所有startcity参数初始化完成
    djkstra(startcity)
    print(number_count[endcity], rescue_count[endcity])
