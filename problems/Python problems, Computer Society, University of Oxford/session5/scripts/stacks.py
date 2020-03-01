#graphs
#stacks
def calc(instructions):
    stack = []
    for instruction in instructions:
        if instruction == "+":
            x = stack.pop();
            y = stack.pop();
            stack.append(x+y)
        elif instruction == "-":
            x = stack.pop();
            y = stack.pop();
            stack.append(x*y)
        elif instruction == "*":
            x = stack.pop();
            y = stack.pop();
            stack.append(x*y)
        elif instruction == "/":
            x = stack.pop();
            y = stack.pop();
            stack.append(x/y)
        elif instruction == "max":
            x = stack.pop();
            y = stack.pop();
            stack.append(max(x,y))
        elif instruction == "^":
            x = stack.pop();
            y = stack.pop();
            stack.append(pow(x,y))
        else:
            stack.append(instruction)
    return stack

def convert(infix):
    out = []
    check = 0
    low = -1
    high = -1
    
    while len(infix) > 0:
        for i in range(0,len(infix)):
            if check == 0:
                if infix[i] == "(":
                    if low == -1:
                        low = i
                if infix[i] == ")":
                    high = i
                if low == high:
                    check = 1
                else:
                    inner_infix = []
                    for j in range(low, high):
                        inner_infix.append(infix[j])
                        del infix[j]
                    out.append(convert(inner_infix))
            elif check == 1:
                #later
    
    return out

print(calc([2, 3, "^"]))

