from typing import List

def bubblesort():
  size = len(nums)
  for i in range(size-1):
    for j in range(size-i-1):
      if nums[j] > nums[j+1]:
        nums[j], nums[j+1] = nums[j+1], nums[j]

nums = [4, 5, 1, 2, 3]
print(nums)
bubblesort()
print(nums)