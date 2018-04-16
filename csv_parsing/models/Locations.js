const mongoose = require("mongoose");

var LocationSubSchema = new mongoose.Schema({
    name: {
      type: String,
      required: true,
      trim: true,
    },
    description: {
      type: String,
      required: true,
      trim: true,
    },
    encodingType: {
      type: String,
      default: "application/vnd.geo+json",
      required: true
    },
    location: {
      type: {
        type: String,
        default:'Point',
        required: true
      },
      coordinates: {
        type: [Number],
        index: "2dsphere",
        required: true
      },
    }
});

var Locations = mongoose.model("Locations", LocationSubSchema);

module.exports = { Locations };
