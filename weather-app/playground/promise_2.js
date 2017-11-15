//  make a function that wraps a request returning a promise.
const request = require('request');
var geocodeAddress = (address) =>  {
  return new Promise((resolve, reject) => { // wraps the request function call inside a promise.
    var encodedAddress = encodeURIComponent(address);

    request({
      url: `http://maps.googleapis.com/maps/api/geocode/json?address=${encodedAddress}`,
      json: true,
    }, (error, response, body) => { // callback that fires when the HTTP request returns
      // console.log(JSON.stringify(error, undefined, 2)); // to pretty print the object
      if(error){
        reject(Error("Unable to connect to Google servers"));
      } else if (body.status === "ZERO_RESULTS"){
        reject(Error('Unable to find that address'));
      } else if(body.status === 'OK'){
        resolve({
          address: body.results[0].formatted_address,
          Latitude: body.results[0].geometry['location']['lat'],
          Longitude: body.results[0].geometry.location.lng,
        });
        // console.log(`Address: ${body.results[0].formatted_address}`);
        // console.log(`Latitude: ${}`);
        // console.log(`Longitude: ${body.results[0].geometry.location.lng}`);
      }
    });
  });
};

geocodeAddress('0000000').then((location) => { // success callback
  console.log(JSON.stringify(location, undefined, 2));
}, (errorMessage) => { // error callback
  console.log(errorMessage);
});
