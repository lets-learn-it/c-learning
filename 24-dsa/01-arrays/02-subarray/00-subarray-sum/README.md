# Subarray Sum

## Prefix Sums

- find sums of all prefixes & store in separate array
- for every possible subarray find sum
- find max

## Kadane's Algorithm

- local_max = 0 & global_max = INT_MIN
- Loop over array
  - local_max = max(current_ele, current_ele + local_max)
  - if local_max > global_max then global_max = local_max
- global_max is answer
