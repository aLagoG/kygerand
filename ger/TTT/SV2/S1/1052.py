def prime(a):
    if a < 2: return False
    if a == 2 or a == 3: return True 
    if a % 2 == 0 or a % 3 == 0: return False
 
    maxDivisor = a**0.5
    d, i = 5, 2
    while d <= maxDivisor:
        if a % d == 0: return False
        d += i 
        i = 6 - i
    return True

