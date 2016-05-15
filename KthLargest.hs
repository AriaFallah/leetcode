module LC where

import Data.List (sort)

kthLargest :: Int -> [Int] -> Int
kthLargest k = last . take k . sort
