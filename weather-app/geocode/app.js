const request = require('request');

const yargs = require('yargs');

const geocode = require('./geocode/geocode.js');

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

console.log(geocode.geocodeAddress(argv.address));
