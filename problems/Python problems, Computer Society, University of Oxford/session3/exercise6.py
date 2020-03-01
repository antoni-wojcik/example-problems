def sum2(xs, ys):
    out = []
    len_long = 0
    if len(xs) > len(ys):
        len_long = len(xs)
    else:
        len_long = len(ys)
        
    for i in range(0, len_long):
        if len(xs) > len(ys):
            if i < len(ys):
                out.append(xs[i]+ys[i])
            else:
                out.append(xs[i])
        else:
            if i < len(xs):
                out.append(xs[i]+ys[i])
            else:
                out.append(ys[i])

    return out
                

def test(test_case_xs, test_case_ys, expected):
    actual = sum2(test_case_xs, test_case_ys)
    if actual == expected:
        print("Passed test for " + str(test_case_xs) + ", " + str(test_case_ys))
    else:
        print("Didn't pass test for " + str(test_case_xs) + ", " + str(test_case_ys))
        print("The result was " + str(actual) + " but it should have been " + str(expected))

test([], [], [])
test([1, 2], [3, 4], [4, 6])
test([-10, 10, 20], [10, -10, -20], [0, 0, 0])
test([1, 2, 3, 4, 5], [1, 2, 3], [2, 4, 6, 4, 5])
test([1, 2, 3], [1, 2, 3, 4, 5], [2, 4, 6, 4, 5])
