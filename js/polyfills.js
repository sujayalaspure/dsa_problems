// console.log("polyfills.js")

const arr = [1, 2, 3, 4, 5]
const arr2 = ["a", "b", "c"]

// const value = arr.push(4) // [1, 2, 3, 4]
Array.prototype.myPush = function (item) {
  const context = this
  const size = context.length
  context[size] = item
  return size
}
// const value2 = arr.myPush(4) // [1, 2, 3, 4]
// console.log(value2)

// const value = arr.pop() // [1, 2]
Array.prototype.myPop = function () {
  const context = this
  context.length--
  return context.length
}
// const value2 = arr.myPop(4) // [1, 2, 3, 4]
// console.log(value2)

const value = arr.shift() // remove first element from the array return removed element
Array.prototype.myShift = function () {
  const context = this
  context.length--
  return context.length
}
// const value2 = arr.myShift(4) // [1, 2, 3, 4]
// console.log(value2)

// arr.unshift(0); // [0, 1, 2, 3]
// ['a', 'b'].concat('c'); // ['a', 'b', 'c']
// arr2.join('-'); // a-b-c
// arr2.slice(1); // ['b', 'c']
// arr2.indexOf('b'); // 1
// arr2.includes('c'); // true
// [3, 5, 6, 8].find((n) => n % 2 === 0); // 6
// [2, 4, 3, 5].findIndex((n) => n % 2 !== 0); // 2
// [3, 4, 8, 6].map((n) => n * 2); // [6, 8, 16, 12]
// [1, 4, 7, 8].filter((n) => n % 2 === 0); // [4, 8]
// [2, 4, 3, 7].reduce((acc, cur) => acc + cur); // 16
// [2, 3, 4, 5].every((x) => x < 6); // true
// [3, 5, 6, 8].some((n) => n > 6); // true
// [1, 2, 3, 4].reverse(); // [4, 3, 2, 1]
// [3, 5, 7, 8].at(-2); // 7

console.log(value)
console.log(arr)

// Polyfill of Array.map
// const arr = [1, 2, 3, 4, 5]

const mapResult = arr.map((item) => item * 2)
// console.log(mapResult)

Array.prototype.myMap = function (callback) {
  let context = this
  let result = []
  let idx = 0
  for (let item of context) {
    result[idx] = callback(item)
    idx++
  }
  return result
}

const mapResult2 = arr.myMap((item) => item * 2)
// console.log(mapResult2)

// polyfill of reduce

const reduceResult = arr.reduce((old, item) => old * item, 1)
// console.log(reduceResult)

Array.prototype.myReduce = function (callback, initialValue) {
  const context = this
  let result = initialValue
  for (let item of context) {
    result = callback(result, item)
  }

  return result
}

const reduceResult2 = arr.myReduce((old, item) => old * item, 1)
// console.log(reduceResult2)
