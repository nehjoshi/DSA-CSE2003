from dis import dis


top = -1
maxSizeStack = 5
maxSizeArray = 4
def initializeStack():
    stack = []
    return stack

def createArray(stack):
    array = []
    stack.append(array)
    return stack

def push(stack, id):
    global top
    if (top==-1):
        stack = createArray(stack)
        stack[top+1].append(id)
        top += 1
    else:
        if (len(stack[top])<maxSizeArray):
            stack[top].append(id)
        else:
            if (top != maxSizeStack-1):
                stack = createArray(stack)
                stack[top+1].append(id)
                top += 1
            else:
                print("Stack is full")
        
def pop(stack):
    global top
    if (top==-1):
        print("Stack is empty, nothing to pop")
    else:
        stack[top].pop()
        if (len(stack[top])==0):
            stack.pop()
            top -= 1

def display(stack):
    global top
    if (top==-1):
        print("Stack is empty")
    else:
        for i in range(top, -1, -1):
            print(stack[i])
    

stack = initializeStack()
push(stack, 1)
push(stack, 2)
push(stack, 3)
push(stack, 4)
push(stack, 5)
push(stack, 6)
push(stack, 7)

pop(stack)
pop(stack)  
pop(stack)
display(stack)




