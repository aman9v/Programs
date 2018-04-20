const mongoose = require("mongoose");
const { encodingTypes } = require("../constants/constants");


const sensorSchema = new mongoose.Schema({
  name: {
    type: String,
    required: true,
    trim: true
  },
  description: {
    type: String,
    required: true,
    trim: true
  },
  encodingType: {
    type: String,
    enum: [encodingTypes.PDF, encodingTypes.SENSOR_ML, encodingTypes.TYPE_DESCRIPTION],
    required: true,
  },
  metadata: {
    type: String,
    required: true
  }
});

const Sensors = mongoose.model("Sensors", sensorSchema);

module.exports = { Sensors };
