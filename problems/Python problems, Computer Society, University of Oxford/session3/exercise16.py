def poly_sum(xs, ys):
    out = []
    if len(xs) > len(ys):
        out = xs
        for i in range(0, len(ys)):
            out[i] = out[i] + ys[i]
    else:
        out = ys
        for i in range(0, len(xs)):
            out[i] = out[i] + xs[i]
    return out

def test(test_case_xs, test_case_ys, expected):
    actual = poly_sum(test_case_xs, test_case_ys)
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
