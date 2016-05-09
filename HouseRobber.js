// https://leetcode.com/problems/house-robber/

/**
 * @param {number[]} nums
 * @return {number}
 */
function rob(nums) {
  'use strict' // Allow block scoping

  // Edge cases
  if (nums.length === 0) return 0;
  if (nums.length === 1) return nums[0];
  if (nums.length === 2) return Math.max(nums[0], nums[1]);

  // Store the results
  let max1 = 0
  let max2 = 0

  for (let money of nums) {
    const haul = max1 + money   // max(i - 1) + L[i]
    max1 = Math.max(max2, max1) // max(max(i - 2) + L[i - 1], max(i - 1))
    max2 = haul                 // Assign the haul
  }

  return Math.max(max2, max1)
}
