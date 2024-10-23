def quick_sort(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[-1]
    left = []  # Elements less than the pivot
    right = []  # Elements greater than the pivot
    middle = []  # Elements equal to the pivot

    for x in arr:
        if x < pivot:
            left.append(x)  # Add to left if less than pivot
        elif x > pivot:
            right.append(x)  # Add to right if greater than pivot
        else:
            middle.append(x)  # Add to middle if equal to pivot

    return quick_sort(left) + middle + quick_sort(right)
