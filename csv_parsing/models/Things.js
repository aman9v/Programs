/*jshint esversion:6*/
const mongoose = require('mongoose');

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
  // Locations: [{ type: mongoose.Schema.Types.ObjectID, ref: 'LocationSubSchema' }], // a thing could be deployed at more than one location,
});

var Things = mongoose.model('Things', ThingsSchema);

module.exports = { Things };
