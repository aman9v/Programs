/*jshint esversion:6*/
const mongoose = require('mongoose');
const { Locations } = require("./Locations");

var ThingsSchema = new mongoose.Schema({
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
    type: Object,
  },
  locations: [{ type: mongoose.Schema.Types.ObjectId, ref: 'Locations' }] // a thing could be deployed at more than one location,
});

var Things = mongoose.model('Things', ThingsSchema);

module.exports = { Things };
