const mongoose = require("mongoose");
require("mongoose-type-url");

const ObserverPropsSchema = new Mongoose.Schema({
  name: { type: String, required: true},
  description: { type: String, required: true},
  definition: { type: mongoose.SchemaTypes.Url, required: true }
})

const ObservedProperties = mongoose.model("ObservedProperties", ObserverPropsSchema);

module.exports = { ObservedProperties };
