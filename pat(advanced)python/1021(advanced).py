import sys


def dfs(node):
    if visited[node - 1] == 1:
        return
    visited[node - 1] = 1
    for i in tables[node - 1]:
        dfs(i)


def dfs2(node, depth):
    global maxdepth
    if (visited1[node - 1] == 1):
        return
    visited1[node - 1] = 1
    for i in tables[node - 1]:
        dfs2(i, depth + 1)
    if maxdepth < depth:
        maxdepth = depth
        middle_answer.clear()
        middle_answer.append(node)
    elif maxdepth == depth:
        middle_answer.append(node)


if __name__ == '__main__':
    number_nodes = int(input())
    if number_nodes == 1:
        print(1)
    else:
        tables = [[] for x in range(number_nodes)]
        for i in range(number_nodes - 1):
            line = list(map(int, input().split(' ')))
            node1 = line[0]
            node2 = line[1]
            tables[node1 - 1].append(node2)
            tables[node2 - 1].append(node1)
        visited = [0 for x in range(number_nodes)]
        count = 0
        for i in range(number_nodes):
            if (visited[i] != 1):
                dfs(i + 1)
                count += 1
        if (count > 1):
            # 不是树
            print('Error: %d components' % count)
        else:
            # 是树
            middle_answer = []
            maxdepth = 0
            visited1 = [0 for j in range(number_nodes)]
            dfs2(1, 0)
            final_answer = set(middle_answer)
            visited1 = [0 for j in range(number_nodes)]
            maxdepth = 0
            indexnode = middle_answer[0]
            middle_answer = []
            dfs2(indexnode, 0)
            final_answer = list(final_answer | set(middle_answer))
            final_answer.sort()
            for k in final_answer:
                print(k)
