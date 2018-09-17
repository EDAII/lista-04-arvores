class AvlTree():
    def _init_ (self):
        self.root = None
    def insert(self, node):
        if self.root == None:
            self.root = node
            return self
        elif node.value > self.root:
            self.root.right = self.insert()

class Node():
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
    def left_rotation(self):
        a = self
        aux = self.right
        aux.left = a
        a = aux
        self = a
        return self
    def right_rotation(self):
        a = self
        b = a.left
        b.right = a
        a = b
        return a
    def right_left_rotation(self):
        self.right = self.right.right_rotation
        self = self.left_rotation
        return self
    def left_right_rotation(self):
        self.left = self.left.left_rotation
        self = self.right_rotation
        return self


tree = AvlTree()
tree.root = Node(10)

a = Node(10)
b = Node(9)
c = Node(8)

a.left = b
b.left = c

a = a.right_rotation()
print(a.value, a.right.value, a.left.value)
