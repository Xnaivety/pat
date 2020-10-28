if __name__ == '__main__':
    total_number_colors = int(input())
    line = list(map(int, input().split()))
    number_favorite_color = line[0]
    favorite_color_list = line[1:]
    line = list(map(int, input().split()))
    stripe_length = line[0]
    stripe_list = line[1:]
    index_list = [0 for i in range(number_favorite_color)]
    for i in range(stripe_length):
        for j in range(number_favorite_color):
            if stripe_list[i] == favorite_color_list[j]:
                index_list[j] = max(index_list[0:j + 1]) + 1
                break
    print(max(index_list))