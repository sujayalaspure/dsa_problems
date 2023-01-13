// console.log("polyfills.js")

// Polyfill of Array.map
const arr = [1, 2, 3, 4, 5]

const arr2 = arr.map((item) => item * 2)
// console.log(arr2)

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

const arr3 = arr.myMap((item) => item * 2)
// console.log(arr3)

// polyfill of reduce

const reduceResult = arr.reduce((old, item) => old * item, 1)
console.log(reduceResult)

Array.prototype.myReduce = function (callback, initialValue) {
  const context = this
  let result = initialValue
  for (let item of context) {
    result = callback(result, item)
  }

  return result
}

const reduceResult2 = arr.myReduce((old, item) => old * item, 1)
console.log(reduceResult2)
