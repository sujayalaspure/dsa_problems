let sum = function (a) {
  return function (b) {
    if (!b) return a;
    return sum(a + b);
  };
};

console.log(sum(1)(2)(3)());

// Short ES6 version of the above snippet:
let sum1 = (a) => (b) => b ? sum1(a + b) : a;

console.log(sum1(1)(2)(3)());
