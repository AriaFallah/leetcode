module LC where

import Data.Map (fromListWith, toList)

containsDuplicates :: [Int] -> Bool
containsDuplicates = foldr (\x -> (||) (x > 1)) False . fmap snd . frequency
  where frequency xs = toList (fromListWith (+) [(x, 1 :: Int) | x <- xs])
