if __name__ == '__main__':
    n, k = list(map(int, input().split()))
    students_dict = {}
    for i in range(k):
        this_course_number, this_course_stu_number = list(map(int, input().split()))
        if (int(this_course_stu_number) > 0):
            stu_list_this_course = input().split()
            for j in stu_list_this_course:
                if j in students_dict.keys():
                    students_dict[j].append(this_course_number)
                else:
                    students_dict[j] = [this_course_number]
    queries = input().split()

    for j in range(n):
        i = queries[j]
        print(i, end=' ')
        if i in students_dict.keys():
            print(len(students_dict[i]), end=' ')
            print(' '.join(list(map(str, sorted(students_dict[i])))))
        else:
            print('0')
