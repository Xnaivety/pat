class new_node():
    left_children = 99999
    right_children = 99999

    def __init__(self, node):
        self.myself = node


def traversal(head1, tail1, head2, tail2):  # 1是postorder的头尾，2是inorder的头尾
    length = tail1 - head1 + 1
    if (length <= 0):
        return 99999
    node = postorder[tail1]
    newnode = new_node(node)
    count = 0
    for i in inorder[head2:]:
        count += 1
        if (i == node):  # head2+count是下一个根结点的index
            # 进行左子树的遍历
            newnode.left_children = traversal(head1, head1 + count - 2, head2, head2 + count - 2)
            # 进行右子树的遍历
            newnode.right_children = traversal(tail1 - length + count, tail1 - 1, tail2 - length + count + 1, tail2)
            break
    return newnode


if __name__ == '__main__':
    number_nodes = int(input())
    postorder = list(map(int, input().split()))
    inorder = list(map(int, input().split()))
    level_traversal = [traversal(0, number_nodes - 1, 0, number_nodes - 1)]
    count1 = 0
    while (level_traversal):
        index_node = level_traversal.pop(0)
        if (count1 != 0):
            print(' ', end='')
        print(index_node.myself, end='')
        count1 += 1
        if (index_node.left_children != 99999):
            level_traversal.append(index_node.left_children)
        if (index_node.right_children != 99999):
            level_traversal.append(index_node.right_children)
