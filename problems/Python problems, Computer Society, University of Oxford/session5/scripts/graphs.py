def dfs(g, start, end):

    if start == end:
        return True
    
    stack = []
    stack.append(start)
    print(stack)

    while len(stack) > 0:
        current = stack.pop()
        print(stack)
        for i in g[current]:
            if i == end:
                return True
            stack.append(i)
            print(stack)
    return False


g1 = {"a": ["c"],
      "b": [],
      "c": ["e", "d"],
      "e": ["b", "d"],
      "d": ["f", "g"],
      "f": [],
      "g": ["a"]
      }

print(dfs(g1, "a", "b"))
