def add(*args):
    """Add all numbers provided as arguments. Example:

    >>> add(1, 2, 3)
    6
    >>> add(*range(10))
    45
    >>> add(1, '2')
    Traceback (most recent call last):
    ...
    TypeError: unsupported operand type(s) for +=: 'int' and 'str'
    """
    s = 0
    for num in args:
        s += num
    return s
