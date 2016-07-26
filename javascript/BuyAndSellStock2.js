// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

/**
 * @param {number[]} prices
 * @return {number}
 */
function maxProfit(prices) {
  if (!prices || prices.length === 1) return 0

  let total = 0
  let maxDiff  = 0
  let minPrice = prices[0]

  for (let i = 1; i < prices.length; ++i) {
    if (minPrice > prices[i]) {
      total += maxDiff
      maxDiff = 0
      minPrice = prices[i]
    }
    maxDiff = Math.max(maxDiff, prices[i] - minPrice)
  }
  
  return maxDiff
}
