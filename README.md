# Non-Divisible-Subset
[Link to Challenge](https://www.hackerrank.com/challenges/non-divisible-subset/problem)

"Given a set of distinct integers, print the size of a maximal subset S where the sum of any  numbers in S is not evenly divisible by k."

# Solution
Given three integers x, y, and k:
if and only if x%k + y%k = (0 or k), then x + y is divisible by k.
  
Based on this, we know:
- Our subset can have at most one value x where x%k = 0
- Our subest can have at most one value y where y%k = k/2
- No values x and y can exist in the subset where x%k + y%k = k

## Algorithm
- Count how many elements have %k = 0, 1, 2 , 3 , .... , k-1
- If there are one or more elements with a %k value of 0, add one to max size
- If there are one or more elements with a %k value of k/2, add one to max size (only possible with even k value)
- Go through %k values from 1 up to k/2, comparing each with it's complementary %k value. Pick the more frequent of the two, adding it's frequency to max size. 

## Example
Set:
{1, 9, 5, 12, 13, 6, 17, 19}

k: 3

element % k values: 
{1, 0, 2, 0, 1, 0, 2, 1}

| %k value      | frequency     |
|:-------------:|:-------------:|
| 0             | 3             |
| 1             | 3             |
| 2             | 2             |

- Add one value with %k = 0  (size = 1)                                  
- Values with %k = 1 and %k = 2 are incompatible, so we ditch the values with %k = 2. (size = 4)

Size of maximal subset: 4
