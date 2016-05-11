module LC where

import Data.Map (fromListWith, toList)
import Data.List (sort)

validAnagram :: String -> String -> Bool
validAnagram s t = freq s == freq t
  where freq xs = sort $ toList (fromListWith (+) [(x, 1 :: Int) | x <- xs])
