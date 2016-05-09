module LC where

reverseString :: String -> String
reverseString = foldl (flip(:)) []
