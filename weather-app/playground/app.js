
const yargs = require('yargs');

const geocode = require('../geocode/geocode.js');
const weather = require('../weather/weather');
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

geocode.geocodeAddress(argv.address, (errorMessage, results) => {
  if (errorMessage){
    console.log(errorMessage);
  }else {
    console.log(results.address);
    weather.getWeather(results.Latitude, results.Longitude, (errorMessage, weatherResults) => {
      if (errorMessage){
        console.log(errorMessage);
      }else {
        console.log(`It is currently ${weatherResults.temperature}. It feels like ${weatherResults.apparentTemperature}.`);
      }
    });
  }
});
