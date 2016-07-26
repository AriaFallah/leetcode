// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/**
 * @param {number[]} prices
 * @return {number}
 */
function maxProfit(prices) {
  if (!prices || prices.length === 1) return 0
  let maxDiff = 0
  let minPrice = prices[0]
  for (let i = 1; i < prices.length; ++i) {
    minPrice = Math.min(minPrice, prices[i])
    maxDiff = Math.max(maxDiff, prices[i] - minPrice)
  }
  return maxDiff
}
