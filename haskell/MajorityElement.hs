module LC where

import Data.Map (fromListWith, toList)
import Data.List (sortBy)
import Data.Ord (comparing)

majorityElement :: [Int] -> [Int]
majorityElement xs = take 1 $ reverse $ fst <$> sortBy (comparing snd) frequency
  where frequency = toList (fromListWith (+) [(x, 1 :: Int) | x <- xs])
