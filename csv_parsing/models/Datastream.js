const mongoose = require("mongoose");
const { encodingTypes, observationTypes } = require("../constants/constants");
const { Things } = require("./Things");
const { Sensor } = require("./Sensor");
require("mongoose-type-url");
require("mongoose-geojson-schema");

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
  observationType: {
    type: String,
    enum: [
      observationTypes.OM_CATEGORY_OBSERVATION,
      observationTypes.OM_COUNT_OBSERVATION,
      observationTypes.OM_MEASUREMENT,
      observationTypes.OM_OBSERVATION,
      observationTypes.OM_TRUTH_OBSERVATION,
    ],
    required: true
  },
  observedArea: mongoose.Schema.Types.GeoJSON,
  phenomenonTime: Date,
  resultTime: Date,
  Thing: { type: mongoose.Schema.Types.ObjectId, ref: "Things" },
  Sensor: { type: mongoose.Schema.Types.ObjectId, ref: "Sensor" }
});

const Datastream = mongoose.model("Datastream", DataStreamsSchema);
module.exports = { Datastream };
