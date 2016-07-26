// https://leetcode.com/problems/palindrome-pairs/

function palindromePairs(words) {
  const pairs = []
  for (let i = 0; i < words.length; ++i) {
    const rest = getRest(words, i)
    for (let j = 0; j < rest.length; ++j) {
      const pair = words[i] + rest[j].value
      if (isPalindrome(pair)) pairs.push([i, rest[j].index])
    }
  }
  return pairs
}

function getRest(words, i) {
  return words.reduce(function(acc, el, index) {
    if (i !== index) acc.push({ value: el, index })
    return acc
  }, [])
}

function isPalindrome(word) {
  while (word.length !== 0) {
    if (word[0] !== word[word.length - 1]) return false
    word = word.slice(1, word.length - 1)
  }
  return true
}
