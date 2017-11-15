var square = x => x * x;

console.log(square(5));

// arrow functions do not bind the 'this keyword'
// Also, they do not have the arguments array
var user = {
  name: "Aman",
  sayHi: () => {
    // console.log(aruments); this is not going to work like the one below
    // instead, it accesses the global
    console.log(`Hi. I am ${this.name}`);
  },
  sayHiAlt () { // this syntax of ES6 is used when using functions in object literals
    console.log(arguments);
    console.log(`Hi. I am ${this.name}`);
  }
};
user.sayHiAlt(1, 2, 3);
