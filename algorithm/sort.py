from typing import List
import random

def bubblesort():
  size = len(nums)
  for i in range(size-1):
    for j in range(size-i-1):
      if nums[j] > nums[j+1]:
        nums[j], nums[j+1] = nums[j+1], nums[j]

def helper(begin: int, end: int):
  if begin >= end:
    return
  mid = begin + (end - begin) / 2
  mid = int(mid)
  helper(begin, mid)
  helper(mid+1, end)

  temp = []
  i, j = begin, mid+1
  while i <= mid and j <= end:
    if nums[i] < nums[j]:
      temp.append(nums[i])
      i = i+1
    else:
      temp.append(nums[j])
      j = j+1

  if i == mid+1:
    while j <= end:
      temp.append(nums[j])
      j = j+1
  else:
    while i <= mid:
      temp.append(nums[i])
      i = i+1

  for i in range(begin, end+1):
    nums[i] = temp[i-begin]
      
def mergesort():
  helper(0, len(nums)-1)

#nums = [4, 5, 1, 2, 3]
nums = [random.randint(-100, 100) for i in range(10)]
print(nums)
mergesort()
print(nums)