if __name__ == '__main__':
    max_capacity_of_tank, total_distance, per_unit_distance, number_gas_station = list(map(int, input().split()))
    gas_station_list = []
    road = [None for x in range(total_distance)]
    roadarrive = [1 for x in range(total_distance)]
    for i in range(number_gas_station):
        gas_station_list.append(list(map(float, input().split())))
    gas_station_list.sort(key=lambda x: x[0])
    total_cost = 0
    flag = 1
    while (road != roadarrive):
        this_cost = 0
        if (len(gas_station_list) == 0):
            flag = 0
            break
        index_per_cost, index_distance = gas_station_list.pop(0)
        for i in range(int(index_distance), int(index_distance) + max_capacity_of_tank * per_unit_distance):
            if (i == total_distance):
                break
            if (road[i] == None):
                this_cost += 1 / per_unit_distance * index_per_cost
                road[i] = 1
        total_cost += this_cost
    if (flag == 1):
        print('%.2f' % total_cost)
    elif (flag == 0):
        total_output_distance = 0
        for i in road:
            if (i != None):
                total_output_distance += 1
            else:
                break
        print('The maximum travel distance = %.2f' % total_output_distance)
