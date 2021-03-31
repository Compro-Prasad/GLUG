def top10(*args):
    for i in range(10):
        m = max(args)
        print(m, end=' ')
        args = [j for j in args if j != m]
    print()

import pdb; pdb.set_trace()
top10(1, 2, 3, 99, 100, 15,
      24, 89, 26, 59, 67, 28)
