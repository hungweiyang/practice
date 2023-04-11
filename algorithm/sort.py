from typing import List
import random

# bubble sort
# TC: O(n*n)
# SC: O(1)
def bubbleSort():
  size = len(nums)
  for i in range(size-1):
    for j in range(size-i-1):
      if nums[j] > nums[j+1]:
        nums[j], nums[j+1] = nums[j+1], nums[j]

# merge sort
# TC: O(n*log(n))
# SC: O(n)
class mergeSort:
  def __init__(self, nums):
    self.helper(nums, 0, len(nums)-1)

  def helper(self, nums: List[int], begin: int, end: int):
    if begin >= end:
      return
    mid = begin + (end - begin) / 2
    mid = int(mid)
    self.helper(nums, begin, mid)
    self.helper(nums, mid+1, end)
  
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

class selectionSort:
  def __init__(self, nums: List[int]):
    for i in range(len(nums)-1):
      min = i
      for j in range(i+1, len(nums)):
        if nums[min] > nums[j]:
          min = j
      nums[i], nums[min] = nums[min], nums[i]

class insertionSort:
  def __init__(self, nums: List[int]):
    for i in range(1, len(nums)):
      j = i
      while j > 0 and nums[j] < nums[j-1]:
          nums[j], nums[j-1] = nums[j-1], nums[j]
          j = j-1

class insertionSort2:
  def __init__(self, nums: List[int]):
    for i in range(1, len(nums)):
      for j in range(0, i):
        if nums[i] < nums[j]: nums[i], nums[j] = nums[j], nums[i]

#nums = [4, 5, 1, 2, 3]
nums = [random.randint(-100, 100) for i in range(10)]
print(nums)
insertionSort2(nums)
print(nums)