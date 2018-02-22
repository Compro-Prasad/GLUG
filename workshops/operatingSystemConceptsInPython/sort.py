def mySort(lst, compare=(lambda x, y: x > y)):
    for i in range(len(lst)):
        for j in range(i, len(lst) - 1):
            if (compare(lst[j], lst[j+1])):          # lst[j] < lst[j+1]
                lst[j], lst[j+1] = lst[j+1], lst[j]  # swap
    return lst


f = open("sortinput.txt", "r")
n = int(f.readline())

lst = f.readline().split(" ")            # ["3", "9", "5", "8\n"]
lst = list(map(lambda x: int(x), lst))   # [3, 9, 5, 8]

AorD = f.readline()[:-1]                 # Remove ‘\n’

print("Actual list:", lst)

if (AorD == 'A'):                        # Ascending order
    lst = mySort(lst[:n])
elif (AorD == 'D'):                      # Descending order
    lst = mySort(lst[:n], lambda x, y: x < y)

print("Sorted list:", lst)

f.close()
