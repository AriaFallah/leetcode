// https://leetcode.com/problems/product-of-array-except-self/

function productExceptSelf(nums) {
  const result = [1]
  for (let i = 1; i < nums.length; ++i) {
    result[i] = result[i - 1] * nums[i - 1]
  }

  let acc = 1
  for (let i = nums.length - 1; i > -1; --i) {
    result[i] *= acc
    acc *= nums[i]
  }

  return result
}
