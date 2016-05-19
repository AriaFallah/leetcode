module LC where

isPalindrome :: (Eq a) => [a] -> Bool
isPalindrome = (==) <*> reverse
