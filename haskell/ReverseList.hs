module LC where

import Data.List (foldl')

-- Simple

reverseList2 :: [a] -> [a]
reverseList2 = foldl' (flip(:)) []

-- Do it from scratch for fun

data LinkedList a =
  Node a (LinkedList a)
  | Empty
  deriving (Show)

-- Example:
-- (Node 1 (Node 2 (Node 3 (Node 4 (Node 5 Empty)))))

addToList :: LinkedList a -> a -> LinkedList a
addToList Empty v = Node v Empty
addToList n v = Node v n

foldListR :: (a -> b -> b) -> b -> LinkedList a -> b
foldListR _ acc Empty = acc
foldListR f acc (Node x next) = f x (foldListR f acc next)

foldListL :: (b -> a -> b) -> b -> LinkedList a -> b
foldListL f z xs = foldListR step id xs z
    where step x g a = g $! f a x

reverseList :: LinkedList a -> LinkedList a
reverseList = foldListL addToList Empty
