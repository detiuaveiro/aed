## G04

## EX01

$$ 
O(n) = \sum_{i=1}^{n-2} 1  = n-2 
$$

## EX02

- Best Case: $B(n) = 2$
- Worst Case: $W(n) = 1 + \sum_{i=2}^{n} 1 = 1+ (n-2) = n - 1$
- Average Case: 

$$
    A(n) = 1 + \sum_{i=2}^{n} \frac{1}{n-2}  \times \sum_{j=1}^{i} 1 \\
    A(n) = 1 + \sum_{i=2}^{n} \frac{i}{n-2} \\
    A(n) = 1 + \frac{1}{n-2} \times \sum_{i=2}^{n} i
$$

## EX03

$$
C(n) = \sum_{k=2}^{n-1} \sum_{j=1}^{k-1} \sum_{i=0}^{j-1} 1
= \sum_{k=2}^{n-1} \sum_{j=1}^{k-1} j 
= \sum_{k=2}^{n-1} \frac{k(k-1)}{2} \\
C(n) = \frac{1}{2} \left[ \sum_{k=2}^{n-1} k(k-1) \right] \\
C(n) = \frac{1}{2} \left[ \sum_{k=2}^{n-1} k^2 - \sum_{k=2}^{n-1} k \right] \\
C(n) = \frac{1}{2} \left[ \frac{n(n-1)(2n-1)}{6} - \frac{n(n-1)}{2} \right] \\
C(n) = \frac{n^3}{6} - \frac{n^2}{2} + \frac{n}{3}
$$
