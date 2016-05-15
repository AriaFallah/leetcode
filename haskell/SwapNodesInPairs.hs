module LC where

swapInPairs :: [a] -> [a]
swapInPairs (x:y:ys) = y : x : swapInPairs ys
swapInPairs x = x
