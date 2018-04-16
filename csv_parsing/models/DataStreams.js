const mongoose = require("mongoose"),
require("mongoose-type-url");

const DataStreamsSchema = new mongoose.Schema({
  name: {
    type: String,
    required: true,
    minlength: 3,
    trim: true
  },
  description: {
    type: String,
    required: true,
    minlength: 3,
    trim: true
  },
  unitOfMeasurement: {
    type: Object,
    required: true
  },
});


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
