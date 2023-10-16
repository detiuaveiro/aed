# Recursive Algorithms

## EX01

$$
T(1) = 1 \\
T(n) = n + T \left( \lfloor \frac{n}{2} \rfloor \right)
$$

$$
C(1) = 0 \\
C(n) = 1 + C \left( \frac{n}{2} \right)\\
C(n) = 2 + C \left( \frac{n}{4} \right)\\
C(n) = k + C \left( \frac{n}{2^k} \right)\\
C(n) = log_2(n) + C(1)\\
C(n) = log_2(n)
$$

## EX02

$$
T(1) = 1 \\
T(n) = n + T \left( \lfloor \frac{n}{2} \rfloor \right) +T \left( \lceil \frac{n}{2} \rceil \right)
$$

$$
C(1) = 0 \\
C(n) = 2 + C\left( \lfloor \frac{n}{2} \rfloor \right)+C\left( \lceil \frac{n}{2} \rceil \right)
$$

Let us consider $n = 2^k$ and $k = n$

$$
C(1) = 0 \\
C(n) = 2 + 2 \times C\left( \frac{n}{2} \right)\\
C(n) = 2 + 4 + 4\times C\left( \frac{n}{4} \right)\\
C(n) = 2 + ... + 2^k + 2^kC\left( \frac{n}{2^k} \right)\\
C(n) = \sum_{i=1}^{k} 2^i + 2^k \times C(1) \\
C(n) = 2^{k+1} - 2 = 2(n-1) 
$$

## Master Theorem

$$
T(n) = aT(n/b) + f(n)
$$

where,

$n$ = size of input

$a$ = number of subproblems in the recursion

$n/b$ = size of each subproblem. All subproblems are assumed to have the same size.

$f(n)$ = cost of the work done outside the recursive call, which includes the cost of dividing the problem and cost of merging the solutions

Here, $a ≥ 1$ and $b > 1$ are constants, and $f(n)$ is an asymptotically positive function.

$$
T(n) = aT(n/b) + f(n)
$$

where, $T(n)$ has the following asymptotic bounds:

1. If $f(n) = O(n^{log_b (a-ϵ)})$, then $T(n) = Θ(n^{log_b(a)})$.

2. If $f(n) = Θ(nlogb a)$, then $T(n) = Θ(n^{log_b(a)} \times log(n))$.

3. If $f(n) = Ω(n^{log_b(a+ϵ)})$, then $T(n) = Θ(f(n))$.

$ϵ > 0$ is a constant.

For more details check [here](https://www.scaler.com/topics/data-structures/masters-theorem/).