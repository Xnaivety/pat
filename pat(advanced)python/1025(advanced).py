class testee():
    final_rank = 99999
    local_rank = 99999

    def __init__(self, registration_number, location_number, score):
        self.registration_number = registration_number
        self.location_number = location_number
        self.score = score


if __name__ == '__main__':
    number_ranklist = int(input())
    local_ranklist_list = [[] for x in range(number_ranklist)]
    total_ranklist_list = []
    for i in range(number_ranklist):
        number_testee = int(input())
        for j in range(number_testee):
            line = input().split()
            index_testee = testee(line[0], i + 1, int(line[1]))
            local_ranklist_list[i].append(index_testee)
        index_list = sorted(local_ranklist_list[i], key=lambda x: x.score, reverse=True)
        for m, k in zip(index_list, range(1, number_testee + 1)):
            if (k != 1 and m.score == index_list[k - 2].score):
                m.local_rank = index_list[k - 2].local_rank
                total_ranklist_list.append(m)
            else:
                m.local_rank = k
                total_ranklist_list.append(m)

    l = 0
    index_list = sorted(total_ranklist_list, key=lambda j: j.score, reverse=True)
    for k in index_list:
        l += 1
        if (l != 1 and index_list[l - 2].score == k.score):
            k.final_rank = index_list[l - 2].final_rank
        else:
            k.final_rank = l
    index_list = sorted(total_ranklist_list, key=lambda j: (j.final_rank, j.registration_number))
    print(len(index_list))
    for k in index_list:
        print(k.registration_number, end=' ')
        print(k.final_rank, end=' ')
        print(k.location_number, end=' ')
        print(k.local_rank)
