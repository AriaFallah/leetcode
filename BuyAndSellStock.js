// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  if (!prices || prices.length === 1) return 0;
  var minPrice = prices[0]
  var maxDiff  = 0
  for (var i = 1; i < prices.length; ++i) {
    minPrice = Math.min(minPrice, prices[i])
    maxDiff  = Math.max(maxDiff,  prices[i] - minPrice)
  }
  return maxDiff
}
