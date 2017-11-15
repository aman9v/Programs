/* jshint esversion:6 */

const mongoose = require('mongoose');

mongoose.Promise = global.Promise;
mongoose.connect('mongodb://localhost:27017/SenseTube', {
   useMongoClient: true,
});

module.exports = {mongoose};
