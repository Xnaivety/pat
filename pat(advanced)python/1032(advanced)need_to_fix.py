if __name__ == '__main__':
    node1,node2,number_node = list(map(int,input().split()))
    tables = {}
    for i in range(number_node):
        index_line = input().split()
        tables[int(index_line[0])] = int(index_line[2])
    cnt1 = 0
    index_node = node1
    while(index_node!=-1):
        index_node = tables[index_node]
        cnt1+=1
        if(index_node == -1):
            break;
    index_node = node2
    cnt2 = 0
    while (index_node!=-1):
        index_node = tables[index_node]
        cnt2 += 1
        if (index_node == -1):
            break;
    if(cnt1>cnt2):
        longer =cnt1-cnt2
        index_node1 = node1
        index_node2 = node2
        for i in range(longer):
            index_node1 = tables[index_node1]
        while(index_node1!=index_node2):
            index_node2 = tables[index_node2]
            index_node1 = tables[index_node1]
    else:
        longer =cnt2-cnt1
        index_node1 = node1
        index_node2 = node2
        for i in range(longer):
            index_node2 = tables[index_node2]
        while(index_node1!=index_node2):
            index_node2 = tables[index_node2]
            index_node1 = tables[index_node1]
    if(index_node1==-1):
        print(-1)
    else:
        print('%05d'%index_node1)



