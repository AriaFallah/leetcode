module LC where

import Data.Char (ord)
import Data.List (foldl')

columnToNumber :: String -> Int
columnToNumber s = foldl' (\acc (i, v) -> acc + 26 ^ i * v) 0 values
  where values = zip (reverse [0..(length s -1)]) ((\c -> ord c - 64) <$> s)
