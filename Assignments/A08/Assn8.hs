fac :: Int -> Int
fac 1 = 1
fac n = n * (fac (n-1))

tailFac :: Int -> Int
tailFac n = loop n 1
    where loop o k
            | o == 1 = k
            | otherwise = loop (o - 1) (o * k)

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib(n-1) + fib(n-2)

tailFib :: Int -> Int
tailFib n = loop n 0 1
    where loop o k m
            | o == 0 = k
            | otherwise = loop (o-1) (k + m) (m + 1)
main = do
    print (fac 10)
    print (tailFac 10)
    print (fib 10)
    print (tailFib 10)