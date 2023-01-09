import React, { useState } from "react"
import { StyleSheet, Text, View, FlatList, Pressable } from "react-native"
import useFetch from "./useFetch"

function renderItem({ item }) {
  return (
    <Pressable>
      <Text style={styles.text}>{item}</Text>
    </Pressable>
  )
}

function App() {
  const [skipCount, setskipCount] = useState(0)
  const { response, error, isLoading } = useFetch(
    `https://dummyjson.com/users?skip=${skipCount}&limit=10`,
    "users",
    "firstName"
  )

  const onEndReached = () => {
    setskipCount((prev) => prev + 10)
  }

  console.log(response)
  if (isLoading) return <Text>Loading...</Text>

  return (
    <View style={styles.app}>
      <FlatList
        data={response}
        renderItem={renderItem}
        keyExtractor={(_, index) => index.toString()}
        onEndReached={onEndReached}
      />
    </View>
  )
}

const styles = StyleSheet.create({
  app: {
    marginHorizontal: "auto",
    maxWidth: 500,
    flex: 1,
  },
  logo: {
    height: 80,
  },
  header: {
    padding: 20,
  },
  title: {
    fontWeight: "bold",
    fontSize: "1.5rem",
    marginVertical: "1em",
    textAlign: "center",
  },
  textWrapper: {},
  text: {
    lineHeight: "1.5em",
    fontSize: "1.125rem",
    marginVertical: "1em",
    textAlign: "center",
  },
  link: {
    color: "#1B95E0",
  },
  code: {
    fontFamily: "monospace, monospace",
  },
})

export default App
