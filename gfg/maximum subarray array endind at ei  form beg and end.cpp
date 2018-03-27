answer = -INFINITY
current = 0
for j=1..N:
    current = max(A[j], current + A[j])
    answer = max(answer, current)
    E[j] = current
    
   //----------------------------------------------------------------------- 
current = 0
for j=N..1 by -1:
    current = max(A[j], current + A[j])
    answer = max(answer, current)
    S[j] = current
