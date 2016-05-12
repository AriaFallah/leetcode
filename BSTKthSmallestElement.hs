module LC where

data BinaryTree a =
  Node a (BinaryTree a) (BinaryTree a)
  | Leaf
  deriving (Show)

testTree :: BinaryTree Int
testTree =
  Node 10
  (Node 5
    (Node 1 Leaf Leaf)
    (Node 6 Leaf Leaf))
  (Node 40
    (Node 30 Leaf Leaf)
    (Node 63 Leaf Leaf))

traverseTree :: (a -> b -> b -> b) -> b -> BinaryTree a -> b
traverseTree f z = go
  where go Leaf = z
        go (Node v l r) = f v (go l) (go r)

flatten :: BinaryTree a -> [a]
flatten = traverseTree (\v left right -> left ++ [v] ++ right) []

kthSmallest :: Int -> BinaryTree a -> a
kthSmallest k = last . take k . flatten
