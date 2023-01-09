import { useEffect, useState } from "react"

const useFetch = (url, key, param) => {
  const [currentUrl, setCurrentUrl] = useState("")
  const [response, setResponse] = useState([])
  const [error, setError] = useState("")
  const [isLoading, setIsLoading] = useState("")

  useEffect(() => {
    if (currentUrl !== url) {
      setIsLoading(true)
      fetch(url)
        .then((response) => response.json())
        .then((data) => {
          // const temp =  data[key].filter(item=>item[param])
          setResponse((prev) => [...prev, ...data[key].map((item) => item[param])])
          setCurrentUrl(url)
        })
        .catch((err) => {
          console.log(err)
          setError(err)
        })
        .finally(() => setIsLoading(false))
    }
  }, [url])

  return { response, error, isLoading }
}

export default useFetch
