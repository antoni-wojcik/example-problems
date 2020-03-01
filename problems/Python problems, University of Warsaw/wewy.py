file_name = 'in.txt'
def zad1():
    m = 0
    lines = []
    with open(file_name) as f:
        for line in f:
            if len(line) > m:
                m = len(line)
        f.seek(0)
        for line in f:
            if len(line) == m:
                if line[-1] == '\n':
                    line = line[0:-1]
                lines.append(line)
    return lines

def zad2(nazwa, n):
    lines = []
    with open(nazwa) as f:
        for line in f:
            l = len(line)
            a = False
            if line[-1] == '\n':
                l -= 1
                a = True
            if l == n:
                if a:
                    line = line[0:-1]
                lines.append(line)
    for line in lines:
        print(line)

def zad3(nazwa):
    ans = {}
    with open(nazwa) as f:
        for line in f:
            k = len(line)
            if k in ans:
                ans[k] += 1
            else:
                ans[k] = 1
    for key in ans:
        print(key, ':', ans[key])

def zad4(nazwa):
    ans = {}
    with open(nazwa) as f:
        for line in f:
            for c in line:
                if c == '\n':
                    continue
                if c in ans:
                    ans[c] += 1
                else:
                    ans[c] = 1
    for key in ans:
        print(key, ':', ans[key])

def zad5(nazwa, slowo):
    h = {}
    ans = []
    for c in slowo:
        if not(c in h):
            h[c] = 1
    print(h)
    with open(nazwa) as f:
        for word in f:
            a = True
            for c in word:
                if not(c in h):
                    a = False
                    break
            print(word, a)
            if a == True:
                ans.append(word)
    for word in ans:
        print(word)
                
