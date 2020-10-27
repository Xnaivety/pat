import sys

def make_node(node_cursor,tail_cursor):
    global number_used_node
    number_used_node+=1
    i = node_cursor
    while(i<tail_cursor and number_list[i+1]<number_list[node_cursor]):#寻找左子树结束cursor
        i+=1
    if(i>node_cursor):
        make_node(node_cursor+1,i)
    j = i
    while(j<tail_cursor and number_list[j+1]>=number_list[node_cursor]):#寻找右子树结束cursor
        j+=1
    if j>i:#右子树不空
        make_node(i+1,j)
    final_answer.append(number_list[node_cursor])


def make_node2(node_cursor,tail_cursor):
    global number_used_node
    number_used_node+=1
    i = node_cursor
    while(i<tail_cursor and number_list[i+1]>=number_list[node_cursor]):
        i+=1
    if(i>node_cursor):#左子树不空
        make_node2(node_cursor+1,i)
    j = i
    while(j<tail_cursor and number_list[j+1]<number_list[node_cursor]):
        j+=1
    if j>i:#右子树不空
        make_node2(i+1,j)
    final_answer.append(number_list[node_cursor])

if __name__ == '__main__':
    sys.setrecursionlimit(20000)#调整递归最大深度
    number = int(input())
    number_list = list(map(int,input().split()))
    number_used_node = 0
    length_number_list = len(number_list)
    final_answer = []
    if(len(number_list)==1):#只有一个数
        print('YES')
        print(number_list[0])
    else:#有多个数
        make_node(0,length_number_list-1)
        if(number_used_node!=length_number_list):
            number_used_node = 0
            nodelist = []
            final_answer = []
            make_node2(0,length_number_list-1)
        if(number_used_node!=length_number_list):
            print('NO')
        else:
            print('YES')
            count = 0
            for i in final_answer:
                if count!=0:
                    print(' ',end = '')
                print(i,end = '')
                count+=1



	