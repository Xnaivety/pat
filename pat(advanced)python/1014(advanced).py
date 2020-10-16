class guest():
    start_time = -99999
    finish_time = -99999

    def __init__(self, process_time, rank_number):
        self.process_time = process_time
        self.rank_number = rank_number


class windows():
    start_time = 8 * 60
    severd_finished = 1
    finish_time = -99999
    served_people = -99999

    def __init__(self, rank_number):
        self.rank_number = rank_number


if __name__ == '__main__':
    line1 = list(map(int, input().split()))
    number_windows = line1[0]
    max_each_line = line1[1]
    number_customer = line1[2]
    number_queries = line1[3]
    guests_list = []
    guests_dict = {}
    windows_list = []
    waiting_list = [[] for x in range(number_windows)]
    for i, j in zip(list(map(int, input().split())), range(1, number_customer + 1)):
        index_guest = guest(i, j)
        guests_list.append(index_guest)
        guests_dict[j] = index_guest
    for k in range(number_windows):
        windows_list.append(windows(k))
    # 处理每个人的时间
    for minutes in range(8 * 60, 17 * 60 + 1):
        # 让顾客结束服务
        for i in range(number_windows):
            if (windows_list[i].finish_time == minutes and windows_list[i].severd_finished == 0):
                windows_list[i].severd_finished = 1
                windows_list[i].served_people = -99999
                waiting_list[i].pop(0)
        # 将顾客压入窗口队列
        while (guests_list):
            j = -1
            k = 99999
            for i in range(number_windows):
                if len(waiting_list[i]) < k and len(waiting_list[i]) != max_each_line:
                    j = i
                    k = len(waiting_list[i])
            if j == -1 and k == 99999:
                break
            waiting_list[j].append(guests_list.pop(0))
        # 让顾客开始服务
        for i in range(number_windows):
            if waiting_list[i] and windows_list[i].severd_finished == 1:
                if (minutes < 17 * 60):
                    waiting_list[i][0].start_time = windows_list[i].start_time = minutes
                    windows_list[i].finish_time = waiting_list[i][0].finish_time = waiting_list[i][
                                                                                       0].process_time + minutes
                    windows_list[i].severd_finished = 0
                    windows_list[i].served_people = waiting_list[i][0]
    # 完成处理，进行查询处理
    queries_list = list(map(int, input().split()))
    for i in queries_list:
        if (guests_dict[i].finish_time != -99999):
            hour = int(guests_dict[i].finish_time / 60)
            minutes = guests_dict[i].finish_time % 60
            print('%02d:%02d' % (hour, minutes))
        else:
            print('Sorry')
