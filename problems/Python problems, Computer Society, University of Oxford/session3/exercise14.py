def merge(xs, ys):
    out = []
    i = 0
    j = 0
    while i < len(xs) and j < len(ys):
        if xs[i] < ys[j]:
            out.append(xs[i])
            i += 1
        else:
            out.append(ys[j])
            j += 1

    while i < len(xs):
        out.append(xs[i])
        i += 1

    while j < len(ys):
        out.append(ys[j])
        j += 1

    return out

def merge_sort(xs):
    if len(xs) > 1:
        first_half = xs[:(len(xs) // 2)]
        second_half = xs[(len(xs) // 2):]
        merge_sort(first_half)
        merge_sort(second_half)
        xs = merge(first_half, second_half)
    return xs

def test(test_case_xs, expected):
    actual = merge_sort(test_case_xs)
    if actual == expected:
        print("Passed test for " + str(test_case_xs))
    else:
        print("Didn't pass test for " + str(test_case_xs))
        print("The result was " + str(actual) + " but it should have been " + str(expected))

test([], [])
test([0], [0])
test([1, 2], [1, 2])
test([2, 1], [1, 2])
test([4, 3, 2, 1], [1, 2, 3, 4])
test([1, 2, 3, 4, 5, 6, 7, 8], [1, 2, 3, 4, 5, 6, 7, 8])
test([8, 7, 6, 5, 4, 3, 2, 1], [1, 2, 3, 4, 5, 6, 7, 8])
test([8, 7, 6, 5, 4, 3, 2, 1, 10, 9], [1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
