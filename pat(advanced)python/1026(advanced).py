def print_time(time):
    hh = time // 3600
    mm = (time % 3600) // 60
    ss = (time % 3600) % 60
    print('%02d:%02d:%02d' % (hh, mm, ss), end=' ')


def print_waiting_time(waiting_time):
    mm = int(waiting_time / 60 + 0.5)
    print(mm)


class pair_players():
    serving_time = None
    waiting_time = None

    def __init__(self, arriving_time, playing_time, vip_card):
        self.arriving_time = arriving_time
        self.playing_time = playing_time
        self.vip_card = vip_card


class table():
    serving_time = None
    finish_serving_time = None
    served_pair = 0

    def __init__(self, vip_card, number):
        self.vip_card = vip_card


if __name__ == '__main__':
    total_number_pair_players = int(input())
    outdoor_player_list = []
    for i in range(total_number_pair_players):
        line = input().split()
        hh = int(line[0][0:2])
        mm = int(line[0][3:5])
        ss = int(line[0][6:])
        time = hh * 3600 + mm * 60 + ss
        index_play_time = int(line[1]) * 60
        outdoor_player_list.append(pair_players(time, index_play_time, int(line[2])))
    outdoor_player_list.sort(key=lambda s: s.arriving_time)
    output_outdoor_player_list = []
    line = list(map(int, input().split()))
    number_tables = line[0]
    vip_table_number_list = list(map(int, input().split()))
    vip_table_number_list = list(set(vip_table_number_list))
    vip_table_number_list.sort()
    vip_tables_list = []
    tables_list = []
    for i in range(1, number_tables + 1):
        if i not in vip_table_number_list:
            index_table = table(0, i)
            tables_list.append(index_table)
        else:
            index_table = table(1, i)
            tables_list.append(index_table)
            vip_tables_list.append(index_table)
    indoor_player_list = []
    indoor_vipplayer_list = []
    number_empty_vip_tables = len(vip_tables_list)
    number_empty_tables = len(tables_list)

    for seconds in range(8 * 3600, 21 * 3600):
        # 送客
        for i in tables_list:
            if (i.finish_serving_time == seconds):
                if (i.vip_card == 1):
                    number_empty_vip_tables += 1
                number_empty_tables += 1
                i.finish_serving_time = None
                i.serving_time = None
        # 如果时间到了就进入场馆
        if (outdoor_player_list and outdoor_player_list[0].arriving_time == seconds):  # 加入普通队列
            indoor_player_list.append(outdoor_player_list[0])
            if (outdoor_player_list[0].vip_card == 1):  # 加入vip队列
                indoor_vipplayer_list.append(outdoor_player_list[0])
            outdoor_player_list.pop(0)
        # 先处理vip队列
        while (indoor_vipplayer_list and number_empty_vip_tables != 0):
            for i in vip_tables_list:
                if (i.serving_time == None):
                    number_empty_vip_tables -= 1
                    number_empty_tables -= 1
                    i.serving_time = indoor_vipplayer_list[0].serving_time = seconds
                    indoor_vipplayer_list[0].waiting_time = seconds - indoor_vipplayer_list[0].arriving_time
                    if (indoor_player_list[0].playing_time >= 7200):
                        i.finish_serving_time = seconds + 7200
                    else:
                        i.finish_serving_time = seconds + indoor_vipplayer_list[0].playing_time
                    i.served_pair += 1
                    output_outdoor_player_list.append(indoor_vipplayer_list[0])
                    # vip队列除去这个人
                    indoor_vipplayer_list.pop(0)
                    # 普通队列除去这个人
                    for i in indoor_player_list:
                        if (i.vip_card == 1):
                            j = i
                            break
                    indoor_player_list.remove(j)
                    break
        # 处理普通队列
        while (indoor_player_list and number_empty_tables != 0):
            for i in tables_list:
                if (i.serving_time == None):
                    number_empty_tables -= 1
                    if (i.vip_card == 1):
                        number_empty_vip_tables -= 1
                    i.serving_time = indoor_player_list[0].serving_time = seconds
                    indoor_player_list[0].waiting_time = seconds - indoor_player_list[0].arriving_time
                    if (indoor_player_list[0].playing_time >= 7200):
                        i.finish_serving_time = seconds + 7200
                    else:
                        i.finish_serving_time = seconds + indoor_player_list[0].playing_time
                    i.served_pair += 1
                    output_outdoor_player_list.append(indoor_player_list[0])
                    if (indoor_player_list[0].vip_card == 1):
                        indoor_vipplayer_list.pop(0)
                    indoor_player_list.pop(0)
                    break
    for i in output_outdoor_player_list:
        print_time(i.arriving_time)
        print_time(i.serving_time)
        print_waiting_time(i.waiting_time)
    count = 0
    for i in tables_list:
        count += 1
        if (count != 1):
            print(' ', end='')
        print(i.served_pair, end='')
