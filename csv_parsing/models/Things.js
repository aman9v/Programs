/*jshint esversion:6*/
const mongoose = require('mongoose');

var LocationSubSchema = new mongoose.Schema({
    name: String,
    geo: {
      type: [Number], // creates an array of numbers
      // coordinates: [Number], // for storing coordinates
      index: '2dsphere'
    }
});

var ThingsSchema = new mongoose.Schema({
  iot_id: {
    type: Number,
    required: true,
    unique: true,
  },
  name: {
    type: String,
    required: true,
    minlength: 3,
    trim: true,
  },
  description: {
    type: String,
    required: true,
    minlength: 3,
    trim: true,
  },
  properties: { // optional properties
    condition: String,
    Use_Case: String,
  },
  location: [LocationSubSchema], // a thing could be deployed at more than one location
});

var Things = mongoose.model('Things', ThingsSchema);

module.exports = {Things};
