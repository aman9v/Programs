/*jshint esversion:6*/
const mongoose = require('mongoose');

var LocationSubSchema = new mongoose.Schema({
    name: String,
    description: String,
    encodingType: {
      type: String,
      default: "application/vnd.geo+json"
    },
    location: {
      type: { type: String, default:'Point' },
      coordinates: {
        type: [Number],
        index: "2dsphere"
      }
    }
});



var ThingsSchema = new mongoose.Schema({
  "@iot.id": {
    type: Number,
    required: true,
    unique: true,
    alias: "id"
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
    "Deployment condition": String,
    "Case Used": String,
  },
  Locations: [LocationSubSchema], // a thing could be deployed at more than one location
});

var Things = mongoose.model('Things', ThingsSchema);

module.exports = {Things};
