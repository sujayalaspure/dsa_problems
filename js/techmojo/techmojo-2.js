const compareObject = (obj1, obj2) => {
  const size1 = Object.keys(obj1).length
  const size2 = Object.keys(obj2).length

  if (size1 !== size2) return false

  if (size1 === 0 && size2 === 0) return true
  const objKeys = Object.keys(obj1)

  for (let i = 0; i < size1; i++) {
    const key = objKeys[i]
    // console.log(key)
    if (!obj2.hasOwnProperty(key)) return false

    if (obj1[key] !== obj2[key]) return false
  }

  return true
}

console.log(compareObject({ a: 1 }, { b: 1 }))
