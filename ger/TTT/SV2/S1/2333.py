import math
def numLen(num):
  return len(str(num))

def sieve(limit):
    P = [2,3]
    sieve=[False]*(limit+1)
    for x in range(1,int(math.sqrt(limit))+1):
        for y in range(1,int(math.sqrt(limit))+1):
            n = 4*x**2 + y**2
            if n<=limit and (n%12==1 or n%12==5) : sieve[n] = not sieve[n]
            n = 3*x**2+y**2
            if n<= limit and n%12==7 : sieve[n] = not sieve[n]
            n = 3*x**2 - y**2
            if x>y and n<=limit and n%12==11 : sieve[n] = not sieve[n]
    for x in range(5,int(math.sqrt(limit))):
        if sieve[x]:
            for y in range(x**2,limit+1,x**2):
                sieve[y] = False
    for p in range(5,limit):
        if sieve[p] : P.append(p)
    return P



primes = sieve(999999)

while 1:
    try:
        n = input()
        i = 0
        for num in primes:
            if numLen(num) == n: break
            i += 1
                
        print i, len(primes), n

        while numLen(primes[i]) == n and i < len(primes)-1 :
            superprime = True
            candidate = primes[i]

            for k in range(n-1):
                candidate /= 10
                if candidate not in primes:
                    superprime = False
            if superprime: print primes[i]
            i += 1
       
    except EOFError: break