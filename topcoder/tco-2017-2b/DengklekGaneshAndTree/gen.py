import random
import itertools

def printTestCase(labels, parents):
    print('"' + ''.join(labels) + '"')
    print('{' + ', '.join(map(str, parents)) + '}')

def randomTree(n, max_depth):
    return [random.randint(max(0, i-max_depth), i) for i in range(n-1)]

def chainTree(n):
    return range(n-1)

def uChainTree(n):
    leftCount = (n-1)//2
    rightCount = n//2
    return list(range(0, leftCount)) + [0] + list(range(leftCount+1, n-1))

def completeBinaryTree(n):
    return [i//2 for i in range(n-1)]

def starTree(n):
    return [0]*(n-1)

def randomLabels(n, alph=26):
    pool = [chr(ord('a') + i) for i in range(alph)]
    random.shuffle(pool)
    return [pool[random.randint(0, alph-1)] for _ in range(n)]

def randomTree(n, max_depth):
    return [random.randint(max(0, i-max_depth), i) for i in range(n-1)]

def randomTestCases():
    n = 100

    printTestCase(randomLabels(n, 1), randomTree(n, n//3))
    printTestCase(randomLabels(n, 2), randomTree(n, n//3))
    printTestCase(randomLabels(n, 3), randomTree(n, n//3))
    printTestCase(randomLabels(n), randomTree(n, n//3))

    printTestCase(randomLabels(n, 1), chainTree(n))
    printTestCase(randomLabels(n, 2), chainTree(n))
    printTestCase(randomLabels(n, 3), chainTree(n))
    printTestCase(randomLabels(n), chainTree(n))

    printTestCase(randomLabels(n, 1), chainTree(n))
    printTestCase(randomLabels(n), chainTree(n))

    printTestCase(randomLabels(n, 1), completeBinaryTree(n))
    printTestCase(randomLabels(n, 2), completeBinaryTree(n))
    printTestCase(randomLabels(n, 3), completeBinaryTree(n))
    printTestCase(randomLabels(n), completeBinaryTree(n))

def trickyUChains():
    n = 100
    tree = uChainTree(100)
    printTestCase(randomLabels(n, 1), tree)
    printTestCase(randomLabels(n, 2), tree)
    printTestCase(randomLabels(n, 2), tree)
    printTestCase(randomLabels(n, 3), tree)
    printTestCase(randomLabels(n, 3), tree)
    printTestCase(randomLabels(n), tree)
    printTestCase(randomLabels(n), tree)
    printTestCase(randomLabels(n), tree)

    labels = ['a'] * (1 + (n-1)//2) + ['b'] * (n//2)
    printTestCase(labels, tree)

    labels = ['a', 'b'] * (n//2)
    printTestCase(labels, tree)

def maxTestCases():
    n = 1000
    labels = ['a'] + ['b'] * (n-1)
    printTestCase(labels, starTree(n))

    printTestCase(randomLabels(n, 1), randomTree(n, n//3))
    printTestCase(randomLabels(n, 2), randomTree(n, n//2))
    printTestCase(randomLabels(n, 3), randomTree(n, n))
    printTestCase(randomLabels(n, 4), randomTree(n, n))
    printTestCase(randomLabels(n), randomTree(n, n//3))
    printTestCase(randomLabels(n), randomTree(n, n//2))
    printTestCase(randomLabels(n), randomTree(n, n))

def permUChain():
    n = 5
    tree = uChainTree(n)
    for labels in itertools.product(['a', 'b'], repeat=5):
        printTestCase(list(labels), tree)

randomTestCases()
trickyUChains()
maxTestCases()
permUChain()
