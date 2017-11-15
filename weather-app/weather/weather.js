const request = require('request');

var getWeather = (lat, lng, callback) => {
  request({
    url: `https://api.darksky.net/forecast/99981987ce0d8ab62946365b21fc77ef/${lat},${lng}`,
    json: true,
  }, (error, response, body) => {
    if (error){
      callback("unable to connect to Forecast.io");
    } else if (response.statusCode === 400){
      callback('Unable to fetch weather');
    } else if (response.statusCode === 200){
      callback(undefined, {
        temperature: body.currently.temperature,
        apparentTemperature: body.currently.apparentTemperature
      });
    }
  });
};

module.exports.getWeather = getWeather;
