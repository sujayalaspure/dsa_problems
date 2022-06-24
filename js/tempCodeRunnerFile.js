console.log("start");

function doSomething(callbacks) {
  console.log("doSomething");
  setTimeout(callbacks, 0);
}

doSomething(function () {
  console.log("callback");
});

console.log("end");
