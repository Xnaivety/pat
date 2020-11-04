class student():
    def __init__(self, id, name, grade):
        self.id = id
        self.name = name
        self.grade = grade


if __name__ == '__main__':
    line = input().split()
    number_records = int(line[0])
    sorted_column = int(line[1])
    student_list = []
    for i in range(number_records):
        line = input().split()
        index_id = line[0]
        index_name = line[1]
        index_grade = line[2]
        student_list.append(student(index_id, index_name, index_grade))
    if sorted_column == 1:
        student_list.sort(key=lambda x: x.id)
    elif sorted_column == 2:
        student_list.sort(key=lambda x: (x.name, x.id))
    elif sorted_column == 3:
        student_list.sort(key=lambda x: (x.grade, x.id))
    for i in student_list:
        print(i.id, end=' ')
        print(i.name, end=' ')
        print(i.grade)
