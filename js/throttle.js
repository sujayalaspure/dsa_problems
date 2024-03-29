const input = document.getElementById("input")
const defaultText = document.getElementById("default")
const debaunceText = document.getElementById("debaunce")
const throttleText = document.getElementById("throttle")

const debouceFunc = (cb, delay = 1000) => {
  let timeout
  return (...args) => {
    clearTimeout(timeout)
    timeout = setTimeout(() => {
      cb(...args)
    }, delay)
  }
}

const updateDebounceText = debouceFunc((text) => {
  debaunceText.innerText = text
}, 1000)

const throttleFunc = (cb, delay = 1000) => {
  let flag = true
  let lastArgs = null

  return (...args) => {
    if (flag) {
      cb(...args)
      flag = false
      setTimeout(() => {
        if (lastArgs !== null) {
          cb(...lastArgs)
          lastArgs = null
        }
        flag = true
      }, delay)
    } else {
      lastArgs = args
    }
  }
}

const updateThrottleText = throttleFunc((text) => {
  throttleText.innerText = text
}, 1000)

input.addEventListener("input", (e) => {
  defaultText.innerText = e.target.value
  updateDebounceText(e.target.value)
  updateThrottleText(e.target.value)
})
