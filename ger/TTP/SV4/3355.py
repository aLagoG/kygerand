def superSieve(n):
    primes = [0 for i in xrange(n+1)]
    p=2
    while(p <= n):         
        if (primes[p] == 0):
            for i in xrange(p * 2, n+1, p):
                primes[i] += 1
                
        p+=1
    # print primes
    return primes


c = 0
for i in superSieve(input()):
    if i == 2: c+=1 
print c