module LC where

reverseOnly :: (Char -> Bool) -> String -> String
reverseOnly f s = replace reversed s
  where reversed = reverse $ filter f s
        replace x [] = x
        replace [] y = y
        replace (x:xs) (y:ys) =
          if f y
            then x : replace xs ys
            else y : replace (x:xs) ys

reverseVowels :: String -> String
reverseVowels = reverseOnly (`elem` "aeiou")
