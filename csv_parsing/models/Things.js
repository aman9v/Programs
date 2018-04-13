/*jshint esversion:6*/
const mongoose = require('mongoose');
const { LocationSubSchema } = require("./Locations");

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
  Locations: [LocationSubSchema], // a thing could be deployed at more than one location,
});

var Things = mongoose.model('Things', ThingsSchema);

module.exports = { Things };
