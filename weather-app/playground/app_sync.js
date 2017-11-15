console.log('Starting app');

setTimeout(() => {
  console.log('Inside callback');
}, 2000);

setTimeout(() => {
  console.log('Another callback');
}, 0);
console.log('Finishing App');
