module LC where

import Data.List (foldl1', tails)

productOfArray :: [Int] -> [Int]
productOfArray xs = f <$> xs
  where p = foldl1' (*)
        f = div (p xs)

productOfArray2 :: [Int] -> [Int]
productOfArray2 xs = zipWith (*) (product <$> heads xs) (product <$> tail (tails xs))
  where heads = reverse . map reverse . tails . reverse
