console.log("start");

function doSomething(callbacks) {
  console.log("doSomething");
  callbacks();
}

doSomething(function () {
  console.log("callback");
});

console.log("end");
