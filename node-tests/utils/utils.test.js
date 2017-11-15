// a function in mocha that lets us define a test case. Takes two arguments.
// notice how "it" reads like a sentence. This is called Behaviorial Driven Development
const expect = require('expect');
const utils = require('./utils');

// describe lets us group test together.
// It's always a good practice to group together tests if they are under the same callback function.
describe('Utils Tests', () => {
  describe('#add', () => {
    it('should add two numbers', () => { // a callback function that acts a test case checker
      var res = utils.add(4, 5);
      expect(res).toBe(9).toBeA('number');
    });
    it('should async add two numbers', (done) => {
      utils.asyncAdd(4, 5, (sum) => {
        expect(sum).toBe(9).toBeA('number');
        done(); // the above expect won't run if done() isn't called. But other tests run just fine as expected
      });
    });
  });// syntax for adding a describe block for specific method

  it('should async square a number', (done) => {
    utils.asyncSquare(5, (square) => {
      expect(square).toBe(25).toBeA('number');
      done();
    });
  });
});


// the callback to "it" returns before the callback function fires due to a delay of 1s
// So, mocha sets all these tests as passed before the callback completes i.e. settimeout returns
// and the assertion is never executed. No matter what the
// assertion is, it always passes i.e. adding assertion will have no effect
//
// To get this fixed, we need to pass a parameter "done". Now, mocha waits for the asyncAdd to return
// after 1 sec timeout and runs the tests after calling 'done()'


// in case of timeout of 2000ms exceeded, one of two possible reasons
// 1. The asynchronous function never calls the callback function.2
// 2. done() was never called



it('should verify first and last names are set', () => {
  var user = utils.setName({age: 25}, "Aman Verma"); // objects in JS are passed by reference. So, the object passed also gets updated
  expect(user)
  .toInclude({
    firstName: "Aman",
    lastName: "Verma",
    age: 25
  })
  .toBeA('object');
});

// it('should expect some value', () => {
//   // expect(12).toNotbe(11);
//   // expect({name: "Aman"}).toEqual({name: "Aman"});
//   // expect([2, 3, 4]).toInclude(4);
//   expect({
//     name: "Aman",
//     age: 25,
//   }).toInclude({
//     age: 25
//   })
// });
