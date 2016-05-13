module LC where

data BinaryTree a =
  Node a (BinaryTree a) (BinaryTree a)
  | Leaf
  deriving (Show)

testTree :: BinaryTree Int
testTree =
  Node 10
  (Node 5
    (Node 1 Leaf undefined)
    (Node 6 Leaf Leaf))
  (Node 40
    (Node 30 Leaf Leaf)
    (Node 63 Leaf Leaf))

traverseTree :: (a -> b -> b -> b) -> b -> BinaryTree a -> b
traverseTree f z = go
  where go Leaf = z
        go (Node v l r) = f v (go l) (go r)

flatten :: BinaryTree a -> [a]
flatten t = traverseTree (\v l r -> l . (v:) . r) id t []

kthSmallest :: Int -> BinaryTree a -> a
kthSmallest k = last . take k . flatten
