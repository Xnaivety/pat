def dfs(station, distance, carry_bike, car_bike):
    global final_car_bike
    global final_carry_bike
    global final_path
    global path
    if (mindis[station] < distance):
        return
    path.append(station)
    if (station == problem_station):  # 到达目的地
        if (mindis[problem_station] > distance):
            final_path = path.copy()
            final_carry_bike = carry_bike
            final_car_bike = car_bike
            final_distance = distance
        else:
            if (carry_bike < final_carry_bike):
                final_path = path.copy()
                final_carry_bike = carry_bike
                final_car_bike = car_bike
                final_distance = distance
            elif (carry_bike == final_carry_bike):
                if (car_bike < final_car_bike):
                    final_path = path.copy()
                    final_carry_bike = carry_bike
                    final_car_bike = car_bike
                    final_distance = distance
        mindis[station] = distance
    else:  # 未到达目的地
        mindis[station] = distance
        for i in tables[station]:
            if (bike_list[i] < perfect_capacity):  # 需要补充车辆
                increase = perfect_capacity - bike_list[i]
                if (car_bike >= increase):  # 车上的车辆够补充
                    car_bike1 = car_bike - increase
                    dfs(i, distance + times_list[station][i], carry_bike, car_bike1)
                else:  # 车上的车辆不够补充
                    carry_bike1 = carry_bike + increase - car_bike
                    car_bike1 = 0
                    dfs(i, distance + times_list[station][i], carry_bike1, car_bike1)
            elif (bike_list[i] == perfect_capacity):  # 完美状态
                dfs(i, distance + times_list[station][i], carry_bike, car_bike)
            elif (bike_list[i] > perfect_capacity):  # 车辆需要被带走
                decrease = bike_list[i] - perfect_capacity
                car_bike1 = car_bike + decrease
                dfs(i, distance + times_list[station][i], carry_bike, car_bike1)
    path.pop()


if __name__ == '__main__':
    # 数据录入
    line = list(map(int, input().split()))
    max_capacity = line[0]
    number_station = line[1]
    problem_station = line[2]
    number_roads = line[3]
    perfect_capacity = max_capacity // 2
    bike_list = list(map(int, input().split()))
    bike_list.insert(0, 5)
    times_list = [[99999 for i in range(number_station + 1)] for x in range(number_station + 1)]
    tables = [[] for x in range(number_station + 1)]
    mindis = [99999 for x in range(number_station + 1)]
    path = []
    final_path = []
    final_carry_bike = 99999
    final_car_bike = 99999
    final_distance = 99999

    for i in range(number_roads):
        line1 = list(map(int, input().split()))
        station1 = line1[0]
        station2 = line1[1]
        tables[station1].append(station2)
        tables[station2].append(station1)
        times_list[station1][station2] = times_list[station2][station1] = line1[2]
    # 处理数据
    dfs(0, 0, 0, 0)
    print(final_carry_bike, end=' ')
    count = 0
    for i in final_path:
        if (count != 0):
            print('->', end='')

        print(i, end='')
        count += 1
    print(' ', end='')
    print(final_car_bike)
