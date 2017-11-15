/*jshint esversion:6*/
const mongoose = require('mongoose');
const {Things} = require('./Things');

var SensorObsSchema = new mongoose.Schema({
  phenomenonTime: {
    type: Date,
    required: true,
    minlength: 1, // [value<NUMBER>, [custom erorr message]]
    trim: true // removes any leading or trailing whitespaces
  },
  results: {
    // type: Boolean,
    // required: true,
    // trim: true,
    temperature: Number,
    humidity: Number,
  },
  iot_id: {type: mongoose.Schema.Types.Number, ref: 'Things'},
});

var Observations = mongoose.model('Observations', SensorObsSchema);

module.exports = {Observations};
