class AvlTree(object):
    def _init_ (self, node=None):
        self.root = node

class Node(object):
    def __init__(self, value, balance=0, left=None, right=None):
        self.value = value
        self.balance = balance
        self.left = left
        self.right = right
    def get_height(self):
        if not self == None:
            right_height = get_height(self.right) + 1
            left_height = get_height(self.left) + 1
            if right_height > left_height:
                return right_height
            else:
                return left_height
        else:
            return 0
    def balancing_calculus(self):
        return (get_height(self.left) - get_height(self.right))
    