def lcs(S):
    S += S      # Concatenate string to it self to avoid modular arithmetic
    f = [-1] * len(S)     # Failure function
    k = 0       # Least rotation of string found so far
    for j in xrange(1,len(S)):
        sj = S[j]
        i = f[j-k-1]
        while i != -1 and sj != S[k+i+1]:
            if sj < S[k+i+1]:
                k = j-i-1
            i = f[i]
        if sj != S[k+i+1]: # if sj != S[k+i+1], then i == -1 
            if sj < S[k]: # k+i+1 = k
                k = j
            f[j-k] = -1
        else:
            f[j-k] = i+1
    return k
print lcs(raw_input())