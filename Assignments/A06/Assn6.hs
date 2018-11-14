-- Write the recursive Haskell functions, mult(mult'), power(power'), and sub(sub'), 
--      using ONLY logical expression, assignment, succ, pred, and if-else (or guard) expressions.

add :: Int -> Int -> Int
add x y = 
    if y == 0 then x
    else add (succ x) (pred y)

add' :: Int -> Int -> Int
add' x y
    | y == 0 = x
    | otherwise = add' (succ x) (pred y)

mult :: Int -> Int -> Int
mult x y =
    if y == 0 then 0
    else add x (mult x (pred y)) 
    
mult' :: Int -> Int -> Int
mult' x y
    | y == 0 = 0
    | otherwise = add x (mult' x (pred y)) 

power :: Int -> Int -> Int
power x y =
    if y == 0 then 1
    else mult x (power x (pred y)) 

power' :: Int -> Int -> Int
power' x y
    | y == 0 = 1
    | otherwise = mult x (power' x (pred y)) 

sub :: Int -> Int -> Int
sub x y =
    if y == 0 then x
    else sub (pred x) (pred y)
    
sub' :: Int -> Int -> Int
sub' x y
    | y == 0 = x
    | otherwise = sub' (pred x) (pred y)

main = do
    print (add 2 3)
    print (add' 3 2)
    print (mult 9 8)
    print (mult' 2 5)
    print (power 2 3)
    print (power' 4 2)
    print (sub 12 2)
    print (sub' 90 3)
