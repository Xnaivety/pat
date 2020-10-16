class guest():
    start_time = -99999
    finish_time = -99999

    def __init__(self, arrive_time, process_time):
        self.arrive_time = arrive_time
        self.process_time = process_time


class windows():
    start_time = -99999
    finish_time = -99999
    is_served = 0


if __name__ == '__main__':
    line = list(map(int, input().split()))
    number_customers = line[0]
    number_windows = line[1]
    guest_list = []
    windows_list = [windows() for x in range(number_windows)]
    total_waiting_time = 0
    for i in range(number_customers):
        line1 = input().split()
        index_arrive_time = list(map(int, line1[0].split(':')))
        arrive_time = index_arrive_time[0] * 3600 + index_arrive_time[1] * 60 + index_arrive_time[2]
        if (arrive_time >= 17 * 3600 + 1):
            continue
        process_time = int(line1[1]) * 60
        guest_list.append(guest(arrive_time, process_time))
    number_valid_customers = len(guest_list)
    guest_list = sorted(guest_list, key=lambda x: x.arrive_time)
    queue = []
    for seconds in range(8 * 3600, 17 * 3600 + 1):
        # 送客
        for i in range(number_windows):
            if windows_list[i].finish_time == seconds and windows_list[i].is_served == 1:
                windows_list[i].is_served = 0

        # 进银行
        while (guest_list and seconds >= guest_list[0].arrive_time):
            queue.append(guest_list.pop(0))

        # 窗口进行办理
        for i in range(number_windows):
            if windows_list[i].is_served == 0 and queue:
                total_waiting_time += seconds - queue[0].arrive_time
                queue[0].start_time = windows_list[i].start_time = seconds
                queue[0].finish_time = windows_list[i].finish_time = seconds + queue[0].process_time
                windows_list[i].is_served = 1
                queue.pop(0)
    print('%.1f' % (total_waiting_time / number_valid_customers / 60))
