module LC where

import Data.Map (fromListWith, toList)

singleNumber :: [Integer] -> [Integer]
singleNumber xs = fst <$> filter (\(_, y) -> y == 1) frequency
  where frequency = toList (fromListWith (+) [(x, 1) | x <- xs])
