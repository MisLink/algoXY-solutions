import Data.List

bsearch xs l u
  | null xs = l
  | length as == m - l + 1 = bsearch bs (m + 1) u
  | otherwise = bsearch as l m
  where
    m = (l + u) `div` 2
    (as, bs) = partition (<= m) xs

minFree xs = bsearch xs 0 (length xs - 1)
