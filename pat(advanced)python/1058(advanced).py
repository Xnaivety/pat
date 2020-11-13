class harry():
    def __init__(self, galleon, sickle, kunt):
        self.galleon = galleon
        self.sickle = sickle
        self.kunt = kunt


if __name__ == '__main__':
    line = input().split()
    index_harry1 = list(map(int, line[0].split('.')))
    A = harry(index_harry1[0], index_harry1[1], index_harry1[2])
    index_harry2 = list(map(int, line[1].split('.')))
    B = harry(index_harry2[0], index_harry2[1], index_harry2[2])
    C = harry(None, None, None)
    C.kunt = A.kunt + B.kunt
    add_kunt = 0
    if (C.kunt >= 29):
        C.kunt -= 29
        add_kunt = 1
    add_sickle = 0
    C.sickle = A.sickle + B.sickle + add_kunt
    if (C.sickle >= 17):
        C.sickle -= 17
        add_sickle = 1
    C.galleon = add_sickle + A.galleon + B.galleon
    print(C.galleon, end='')
    print('.', end='')
    print(C.sickle, end='')
    print('.', end='')
    print(C.kunt)
