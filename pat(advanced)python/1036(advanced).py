import copy

if __name__ == '__main__':
    number_students = int(input())
    highest_female = [None, 'F', None, -99999]
    lowest_male = [None, 'M', None, 99999]
    number_male = 0
    number_female = 0
    for i in range(number_students):
        index_student = input().split()
        if (index_student[1] == 'M'):
            number_male += 1
            if (int(index_student[3]) < int(lowest_male[3])):
                lowest_male = copy.deepcopy(index_student)
        else:
            number_female += 1
            if (int(index_student[3]) > int(highest_female[3])):
                highest_female = copy.deepcopy(index_student)
    if (number_female == 0):
        print('Absent')
    else:
        print(highest_female[0], end=' ')
        print(highest_female[2])
    if (number_male == 0):
        print('Absent')
    else:
        print(lowest_male[0], end=' ')
        print(lowest_male[2])
    if (number_male * number_female != 0):
        print(int(highest_female[3]) - int(lowest_male[3]))
    else:
        print('NA')
