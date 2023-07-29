import sys

input = sys.stdin.readline
N = int(input())

tree = {}

for _ in range(N):
    s, l, r = input().split()
    tree[s] = (l, r)

pre_buf = ""
def preorder(node):
    global pre_buf
    l, r = tree[node]
    pre_buf += node
    if l != ".":
        preorder(l)
    if r != ".":
        preorder(r)

in_buf = ""
def inorder(node):
    global in_buf
    l, r = tree[node]
    if l != ".":
        inorder(l)
    in_buf += node
    if r != ".":
        inorder(r)

post_buf = ""
def postorder(node):
    global post_buf
    l, r = tree[node]
    if l != ".":
        postorder(l)
    if r != ".":
        postorder(r)
    post_buf += node

preorder('A')
inorder('A')
postorder('A')

print(pre_buf)
print(in_buf)
print(post_buf)