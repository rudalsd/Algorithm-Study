N = int(input())
# N의 값에 따라 memo 리스트의 크기 조절, N이 0이라도 리스트가 생성되게 구성하였다.
memo = [0] + [0]* (N)
if N > 0:
    memo[1] = 1
    # for문을 이행하면서 memo[n]의 값이 0에서 n번째 피보나치 수로 바뀌어간다. 
    for n in range(2,N+1):
        memo[n] = memo[n-1] + memo[n-2]

# 구하고 싶은 값은  N번째 피보나치 숫자이다.
#  memo 리스트의 마지막 값이 N번째 피보나치 숫자이므로, 이에 맞게 출력
print(memo[-1])
