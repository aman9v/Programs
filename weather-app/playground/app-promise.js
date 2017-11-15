const axios = require('axios'); // built with Promises
const yargs = require('yargs');

const argv = yargs
  .options({
      a: {
        demand: true,
        alias: 'address',
        describe: 'Address to fetch weather for',
        string: true, // tells yargs to parse arguments as strings
      }
  })
  .help()
  .alias('help', 'h')
  .argv;

var encodedAddress = encodeURIComponent(argv.address);
var geocodeURL = `http://maps.googleapis.com/maps/api/geocode/json?address=${encodedAddress}`

axios.get(geocodeURL)
.then((response) => { // sucess callback when the get request returns
  if (response.data.status === "ZERO_RESULTS"){
    throw new Error('Unable to find that address'); // control reaches the catch block
  }
  // getting lat and long from the response received
  var lat = response.data.results[0].geometry.location.lat;
  var lng = response.data.results[0].geometry.location.lat;
  // calling weatherAPI to get the temperature readings
  var weatherURL = `https://api.darksky.net/forecast/99981987ce0d8ab62946365b21fc77ef/${lat},${lng}`
  console.log(response.data.results[0].formatted_address);
  return axios.get(weatherURL); // chaining calls together
})
.then((response) => { // chained call
  var temperature = response.data.currently.temperature;
  var actualTemperature = response.data.currently.apparentTemperature;
  console.log(`It's currently ${temperature}. It feels like ${actualTemperature}`);
})
.catch((error) => { // failure callback
  if (error.code === "ENOTFOUND") {
    console.log("Unable to connect to API server");
  } else {
    console.log(error.message);
  }
}); // axios knows how to parse JSON data.
// An advantage of using Promises is that it gets rid of nesting and chains the callbacks instead.
