expr = input()

output = ""
op_stack = []
count_bracket = 0

prior = {'(': 0, ')': 3, '+': 1, '-': 1, '*': 2, '/': 2}

for ch in expr:
    if ch.isalpha():
        output += ch
    elif ch ==')':
        while op_stack:
            top = op_stack.pop()
            if top != '(':
                output += top
            else: break
    else:
        while ch != '(' and op_stack:
            if prior[ch] <= prior[op_stack[-1]]:
                output += op_stack.pop()
            else: break
        op_stack.append(ch)

print(output + "".join(list(reversed(op_stack))))



