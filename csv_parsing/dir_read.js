/* jshint esversion:6 */
const dir = require('node-dir');
const csv = require('fast-csv');

const { mongoose } = require('./db/mongoose'); // ES6 object destructuring
const { Things } = require('./models/Things');
const { Observations } = require('./models/Observations');

var __dirname = './sensor_csvs/windspeed';
var allFiles = dir.files(__dirname, { sync:true });
var Files = allFiles.splice(1, 1);


var query = Things.findOne({ name:"Wind Speed" });
var thing_id;

query.exec(function (err, thing) {
  if (err) throw err;
  thing_id = thing.iot_id;
});

dir.readFiles(__dirname, (err, content, next) => { // filecallback
  if (err) throw err;
  csv
    .fromString(content, {headers: true})
    .on("data", (record) => {
      var newObs = new Observations({
        phenomenonTime: record.DateTime,
        results: {
          temperature: record.Temperature,
          humidity: record.Humidity
        },
        iot_id: thing_id
      });
      newObs.save().then((obs) => {
        console.log("New Observation saved to the database", obs);
      }, (error) => {
        console.log("error saving the document to the database");
      });
    })
    .on('end', () => {
      console.log("done reading/parsing this file");
    });
  next();
}, (err, files) => { // finished callback
  if (err) throw error;
  console.log("finished reading all files:");
  // mongoose.disconnect();
});

// module.exports = {dir};
