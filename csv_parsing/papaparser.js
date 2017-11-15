/*jshint esversion:6*/
const Papa = require('papaparse');
const Baby = require('babyparse');

var csvParser = (url, callback) => {
  Baby.parse(url, {
    download: true,
    header: true,
    dynamicTyping: true,
    delimiter: ',',
    complete: function (results, file) {
      callback(results.data);
    },
  });
}
;

csvParser('http://agsense4water.com/senseTube/dht_Fri_Aug_11_00:00:47_2017.csv', (data) => console.log(data));
