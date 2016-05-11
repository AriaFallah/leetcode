module LC where

missingNumber :: [Int] -> Int
missingNumber [] = 0
missingNumber [_] = 1
missingNumber (x:y:ys) = if y - x == 1 then missingNumber ys else x + 1
