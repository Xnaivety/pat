if __name__ == '__main__':
    line = list(map(int, input().split()))
    specific_value = line[1]
    number_list = list(map(int, input().split()))
    final_answer = []
    cursor1 = 0
    cursor2 = 0
    index_value = 0
    index_difference_value = 9999999
    while (cursor1 <= line[0] and cursor2 <= line[0]):
        try:
            if index_value < specific_value:
                index_value += number_list[cursor2]
                cursor2 += 1

            else:
                if 0 <= index_value - specific_value < index_difference_value:
                    index_difference_value = index_value - specific_value
                    final_answer.clear()
                    final_answer.append([cursor1 + 1, cursor2])
                elif index_difference_value == index_value - specific_value:
                    final_answer.append([cursor1 + 1, cursor2])
                index_value -= number_list[cursor1]
                cursor1 += 1
        except:
            break
    for i in final_answer:
        print(i[0], end='-')
        print(i[1])
