var asyncAdd = (a, b) => {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      if (typeof a === 'number' && typeof b === 'number'){
        resolve(a+b);
      }else{
        reject('Arguments must be numbers');
      }
    }, 1500);
  });
};

// var somePromise = new Promise((resolve, reject) => {
//     setTimeout(() => {
//         resolve('Hey, it worked');
//         reject('Something went wrong!');
//     }, 2500);
//  // WE CAN DO ONE OF THESE ACTIONS ONLY ONCE.
// });
//
// somePromise.then((message) => { // Is call only if the promise gets fulfilled or is resolved. Arguments could be a message or user object
//     console.log('Success:', message)                            // It is called with the value passed to resolve.
// }, (error) => {
//   console.log('Error:', error);
// });

//  Both resolve and reject take single arguments
// In callbacks, the arguments of the callback function let us know whether the call was a success or
// a failure. As against this, Promises do this with the help of .then() function.
asyncAdd(5, '7').then((result) => { // calling then on the promise object returned by calling asyncAdd
  console.log('Result:', result);
  return asyncAdd(result, 33); // returns a promise instance to allow the next call.
}, (errorMessage) => {
  console.log(errorMessage);
}).then((result) => {
  console.log('This comes after the previous ".then()". Result should be:', result);
}, (errorMessage) => {
  console.log(errorMessage);
});

// If the first promise is rejected, we get an error message printed but the second successive
// callback function i.e. then() is resolved.
// we can add a functionality that catches error if any of the two callbacks(promise calls) fails.
// asyncAdd(5, '7').then((result) => {
//   console.log('First call results in:', result);
//   return asyncAdd(result, 33);
// }).then((result) => {
//   console.log("second call results in", result);
// }).catch((error) => {
//   console.log('Error if any of the two calls fails');
// });
