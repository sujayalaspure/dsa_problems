// https://practice.geeksforgeeks.org/problems/geek-and-strings3030/1

class TrieNode {
  constructor() {
    this.children = {}
    this.count = 1
    this.isEnd = false
  }
}

class autoComplete {
  root = null
  list = null
  constructor(list) {
    this.root = this.BuildTrie(list)
  }

  BuildTrie(list) {
    const root = new TrieNode()
    for (const word of list) {
      this.insert(root, word)
    }
    console.log(root)
    return root
  }

  insert(root, word) {
    for (const char of word) {
      if (root.children[char]) {
        root.children[char].count++
      } else {
        root.children[char] = new TrieNode()
      }
      root = root.children[char]
    }
    root.isEnd = true
  }

  isStartWith(input) {
    let node = this.root
    let found = true
    let word = ""

    for (const char of input) {
      if (node.children[char]) {
        word += char
        // console.log(char, node.children[char])
        node = node.children[char]
      } else {
        found = false
        break
      }
    }

    return { node: found ? node : null, word }
  }

  getAutoDFS(input) {
    const { node, word } = this.isStartWith(input)
    if (!node) return []
    const words = []
    if (node.isEnd) words.push([word, node.count])
    const [wordsList] = this.DFS(word, node)

    return words.concat(wordsList)
  }

  DFS(word, node) {
    let count = 0
    if (!node) return
    let words = []
    for (const char in node.children) {
      if (node.children[char].isEnd) {
        count = Math.max(count, node.count)
        // console.log(count, node.count)
        words.push([word + char, node.count])
      }
      words = [...words, ...this.DFS(word + char, node.children[char])[0]]
    }
    return [words, count]
  }
}

// const at = new autoComplete(["abracadabra", "geeksforgeeks", "abracadabra", "geeks", "geeksthrill"])

// const queries = ["abr", "geeks", "geeksforgeeks", "ge", "gar"]

// let ans = []
// for (const quer of queries) {
//   const count = at.getAutoDFS(quer)
//   ans.push(count)
//   let maxCount = 0

//   for (const ch of count) {
//     maxCount = Math.max(ch[1], maxCount)
//   }
//   console.log("->", maxCount)
// }

// console.log(ans)

function insert(root, word) {
  let temp = root
  for (const char of word) {
    if (temp.children[char]) {
      temp.children[char].count++
    } else {
      temp.children[char] = new TrieNode()
    }
    temp = temp.children[char]
  }
  temp.isEnd = true
}

function find(root, word) {
  let temp = root

  for (const char of word) {
    if (temp.children[char]) {
      temp = temp.children[char]
    } else {
      return 0
    }
  }
  return temp.count
}

function main() {
  const words = ["abracadabra", "geeksforgeeks", "abracadabra", "geeks", "geeksthrill"]

  const queries = ["abr", "geeks", "geeksforgeeks", "ge", "gar"]

  let root = new TrieNode()

  for (const word of words) {
    insert(root, word)
  }
  let ans = []
  for (const word of queries) {
    ans.push(find(root, word))
  }
  console.log("->>", ans)
}

main()
