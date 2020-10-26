def ad_just(card, position, index):
    index_card = card
    card_order[index] = None
    if card_order[position] != None:
        ad_just(card_order[position], specific_position[position], position)
        adjust[position] = 1
    card_order[position] = index_card


if __name__ == '__main__':
    repeat_time = int(input())
    card_order = ['S1', 'S2', 'S3', 'S4', 'S5', 'S6', 'S7', 'S8', 'S9', 'S10', 'S11', 'S12', 'S13', 'H1', 'H2', 'H3',
                  'H4', 'H5', 'H6', 'H7', 'H8', 'H9', 'H10', 'H11', 'H12', 'H13', 'C1', 'C2', 'C3', 'C4', 'C5', 'C6',
                  'C7', 'C8', 'C9', 'C10', 'C11', 'C12', 'C13', 'D1', 'D2', 'D3', 'D4', 'D5', 'D6', 'D7', 'D8', 'D9',
                  'D10', 'D11', 'D12', 'D13', 'J1', 'J2']
    specific_position = list(map(int, input().split()))
    specific_position = list(map(lambda x: x - 1, specific_position))
    adjust = [0 for i in range(54)]
    for i in range(repeat_time):
        for i in range(0, 54):
            if (adjust[i] == 0):
                ad_just(card_order[i], specific_position[i], i)
    print(' '.join(card_order))
