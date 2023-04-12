import random

class heapSort:
  def __init__(self, nums):
    n = len(nums)
    for i in range(int(n/2-1), -1, -1):
      self.heapify(nums, n, i)

    for i in range(n-1):
      nums[0], nums[n-1-i] = nums[n-1-i], nums[0]
      self.heapify(nums, n-1-i, 0)
  
  def heapify(self, nums, n, mid):
    left = mid*2+1
    right = mid*2+2
    largest = mid
    if left < n and nums[largest] < nums[left]:
      largest = left
    if right < n and nums[largest] < nums[right]:
      largest = right

    if mid != largest:
      nums[mid], nums[largest] = nums[largest], nums[mid]
      self.heapify(nums, n, largest)

#nums = [4, 5, 1, 2, 3]
nums = [random.randint(-100, 100) for i in range(10)]
print(nums)
heapSort(nums)
print(nums)