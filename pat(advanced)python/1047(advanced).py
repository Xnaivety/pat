if __name__ == '__main__':
    number_students, number_courses = list(map(int, input().split()))
    courses = [[] for i in range(number_courses)]
    for i in range(number_students):
        line = input().split()
        index_stu_name = line[0]
        index_number_courses = int(line[1])
        for j in range(index_number_courses):
            courses[int(line[j + 2]) - 1].append(index_stu_name)
    for i in range(number_courses):
        if courses[i]:
            courses[i].sort()
            print(i + 1, end=' ')
            print(len(courses[i]))
            print('\n'.join(courses[i]))  # 运行效率比循环输出高
        else:
            print(i + 1, '0')
