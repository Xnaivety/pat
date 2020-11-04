class book():
    def __init__(self, seven_digit_id_number, book_title, author, key_words, publisher, published_year):
        self.seven_digit_id_number = seven_digit_id_number
        self.book_title = book_title
        self.author = author
        self.key_words = key_words
        self.publisher = publisher
        self.published_year = published_year


if __name__ == '__main__':
    number_book = int(input())
    books_list = []
    for i in range(number_book):
        index_seven_digit_id_number = input()
        index_book_title = input()
        index_author = input()
        index_key_words = input().split()
        index_publisher = input()
        index_published_year = input()
        books_list.append(
            book(index_seven_digit_id_number, index_book_title, index_author, index_key_words, index_publisher,
                 index_published_year))
    books_list = sorted(books_list, key=lambda x: x.seven_digit_id_number)
    for i in range(int(input())):
        input1 = input()
        print(input1)
        index_line = input1.split(': ')  # 请求编号
        request_number = int(index_line[0])
        request_text = index_line[1]
        count = 0
        if (request_number == 1):
            for i in books_list:
                if (i.book_title == request_text):
                    count += 1
                    print(i.seven_digit_id_number)
        elif (request_number == 2):
            for i in books_list:
                if (i.author == request_text):
                    count += 1
                    print(i.seven_digit_id_number)
        elif (request_number == 3):  # 进行列表查询
            for i in books_list:
                for x in i.key_words:
                    if (x == request_text):
                        print(i.seven_digit_id_number)
                        count += 1
                        break
        elif (request_number == 4):
            for i in books_list:
                if (i.publisher == request_text):
                    count += 1
                    print(i.seven_digit_id_number)
        elif (request_number == 5):
            for i in books_list:
                if (i.published_year == request_text):
                    count += 1
                    print(i.seven_digit_id_number)
        if (count == 0):
            print('Not Found')
