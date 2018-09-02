import random
import itertools

def printTestCase(chains, lengths):
    print('{' + ', '.join(map(lambda s: '"' + s + '"', chains)) + '}')
    print('{' + ', '.join(map(str, lengths)) + '}')

def comper(n):
    s = [chr(ord('a')+i) for i in range(n)]
    chains = [''.join(t) for t in itertools.permutations(s)]
    lengths = [random.randint(1,n) for _ in range(len(chains))]
    printTestCase(chains, lengths)

def tricky1():
    def randStr(l, alph):
        return ''.join([chr(ord('a') + random.randint(0, alph-1)) for _ in range(l)])

    s = 'xyz'
    chains = [a+b+c+randStr(10, 3) for a in s for b in s for c in s]

    lengths = [random.randint(1, min(5, len(chains[i]))) for i in range(25)]
    printTestCase(chains, lengths)
    lengths = [i%3+1 for i in range(25)]
    printTestCase(chains, lengths)
    lengths = [min(i//5+1, len(chains[i])) for i in range(25)]
    printTestCase(chains, lengths)
    lengths = [1]* len(chains)
    printTestCase(chains, lengths)
    lengths = [2]* len(chains)
    printTestCase(chains, lengths)

    newChains = chains + [randStr(13, 26) for _ in range(23)]
    lengths = [random.randint(1, min(10, len(chains[i]))) for i in range(len(chains))]
    printTestCase(newChains, lengths)

def permu(n, l):
    def randStr():
        s = [chr(ord('a')+i) for i in range(l)]
        random.shuffle(s)
        return ''.join(s)

    chains = [randStr() for _ in range(n)]
    m = n//2 + random.randint(0, n//2)
    lengths = [random.randint(1, len(chains[i])) for i in range(n)]
    printTestCase(chains, lengths)


def reallyRandom(n, l, alph):
    def randStr():
        return ''.join([chr(ord('a') + random.randint(0, alph-1)) for _ in range(l)])

    chains = [randStr() for _ in range(n)]
    m = n//2 + random.randint(0, n//2)
    lengths = [random.randint(1, len(chains[i])) for i in range(n)]
    printTestCase(chains, lengths)

comper(4)
comper(4)
comper(4)
comper(4)
comper(4)

# printTestCase(['a'], [1])
# printTestCase(['aa'], [1])
# printTestCase(['aa'], [2])
# printTestCase(['ab'], [1])
# printTestCase(['ab'], [2])
# printTestCase(['ba'], [1])
# printTestCase(['ba'], [2])
# printTestCase(['a']*50, [1]*50)
# printTestCase([chr(ord('a')+(i % 26)) for i in range(50)], [1]*50)
# printTestCase([chr(ord('a')+(i % 26)) for i in range(50)], [1]*26)

# printTestCase([chr(ord('a')+(i % 26)) for i in range(50)], [1]*26)

# tricky1()
# reallyRandom(10, 10, 2)
# reallyRandom(10, 50, 26)
# reallyRandom(20, 10, 2)
# reallyRandom(20, 50, 26)
# reallyRandom(30, 2, 2)
# reallyRandom(30, 3, 3)
# reallyRandom(40, 1, 2)
# reallyRandom(50, 2, 2)
# reallyRandom(50, 40, 5)
# reallyRandom(50, 40, 5)
# reallyRandom(50, 40, 5)
# reallyRandom(50, 40, 5)
# reallyRandom(50, 40, 5)
# reallyRandom(50, 40, 5)
# reallyRandom(50, 40, 6)
# reallyRandom(50, 40, 6)
# reallyRandom(50, 40, 6)
# reallyRandom(50, 40, 6)
# reallyRandom(50, 40, 6)
# reallyRandom(50, 40, 6)
# reallyRandom(50, 40, 7)
# reallyRandom(50, 50, 8)
# reallyRandom(50, 50, 9)
# reallyRandom(50, 50, 10)
# reallyRandom(50, 50, 2)
# reallyRandom(50, 50, 10)
# reallyRandom(50, 50, 26)
# reallyRandom(50, 50, 26)
# reallyRandom(50, 50, 26)
# reallyRandom(50, 50, 26)
# reallyRandom(50, 50, 26)

# permu(10, 3)
# permu(50, 2)
# permu(50, 3)
# permu(50, 4)
# permu(50, 4)
# permu(50, 4)
# permu(50, 4)
# permu(50, 4)
# permu(50, 4)
# permu(50, 5)
# permu(50, 5)
# permu(50, 5)
# permu(50, 5)
# permu(50, 5)
# permu(50, 5)
# permu(50, 5)
# permu(50, 5)
# permu(50, 5)
# permu(50, 6)
# permu(50, 26)
# permu(50, 26)
# permu(50, 26)
