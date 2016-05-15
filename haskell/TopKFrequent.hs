module LC where

import Data.Map (fromListWith, toList)
import Data.List (sortBy)
import Data.Ord (comparing)

topKFrequent :: [Int] -> Int -> [Int]
topKFrequent xs k = take k $ reverse $ fst <$> sortBy (comparing snd) frequency
  where frequency = toList (fromListWith (+) [(x, 1 :: Int) | x <- xs])
