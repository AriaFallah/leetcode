module LC where

import Data.Map (fromListWith, toList)

singleNumber :: [Int] -> [Int]
singleNumber xs = fst <$> filter f frequency
  where
    frequency = toList (fromListWith (+) [(x, 1) | x <- xs])
    f (_, y) = y == 1
