/*jshint esversion:6*/

const csv = require('fast-csv');
const express = require('express');
const bodyParser = require('body-parser');
const { entities } = require("./constants/constants");
// const {dir} = require('./dir_read');
const { mongoose } = require('./db/mongoose'); // ES6 object destructuring
const { Things } = require('./models/Things');
const { Observations } = require('./models/Observations');
const { Locations } = require('./models/Locations');

var app = express();

app.use(bodyParser.json());

// csv
//   .fromPath("./rainGauge_Fri_Aug_11_12_12_51_2017.csv", {headers: true})
//   .on("data", (record) => {
//     var newObs = new Observations({Timestamp: record.Date, Rain: record.Rain});
//     newObs.save().then((doc) => {
//       console.log(`doc saved to the database: ${doc}`);
//     }, (error) => {
//       console.log('Error saving the document');
//     });
//   })
//   .on('end', () => {
//     console.log("End of file");
//   });

// var newThing = new Things({
//   iot_id: 2,
//   name: 'Wind Speed',
//   description: "Sensor to measure Wind Speed",
//   properties: {
//     condition: "Deployed in the field",
//   }
// });

// newThing.save().then((thing) => {
//   console.log(JSON.stringify(thing, undefined, 2));
// }, (error) => {
//   console.log('Error inserting the document');
// });

app.get("/", (req, res) => {
  const value = entities.map((entity) => {
    return {
        name: entity,
        url: "localhost:8080/" + entity
    };
  });
  res.send({value: value});
});

app.get('/Things', (req, res) => {
  Things.find().then((Things) => {
    res.send(Object.assign({}, { "@iot.count": Things.length }, Things, {
      "@iot.selfLink": "localhost:3000/OGCSensorThings/v1.0/Things"
    }));
  }, (error) => res.status(404).send(error));
});

app.get('/Locations', (req, res) => {
  Locations.find().then((locations) => {
    res.send(Object.assign())
  });
});

app.post("/Locations", (req, res) => {
  var newLocation = new Locations(req.body);
  newLocation.save().then((location) => {
    res.send(Object.assign({}, { "@iot.id": location._id, "@iot.selfLink": "localhost:3000/Locations/" + location._id }, location.toObject(), { "Things@iot.navigationLink": "link", "HistoricalLocations@iot.navigationLink": "link"}));
  }, (error) => res.status(400).send(error));
});

app.get("Things/:id", (req, res) => {

})

app.post("/Things", (req, res) => {
  var newThing = new Things(req.body);
  newThing.save().then((thing) => {
    if (req.body["Locations"]) {
      if (req.body["Locations"][0]["@iot.id"]) {
        let locationId = req.body["Locations"][0]["@iot.id"];
        Locations.findOne({ _id: locationId }).then((location) => {
          res.send(Object.assign({}, { "@iot.id": thing._id }, thing.toObject(), { "Locations@iot.navigationLink": location._id }));
        }, (error) => res.status(404).send("No location with the given id exists"));
      } else {
        var newLoc = new Locations(req.body["Locations"][0]);
        newLoc.save().then((location) => {
          res.send(Object.assign({}, { "@iot.id": thing._id }, thing.toObject(), { "Locations@iot.navigationLink": location._id }));
        }, (error) => res.status(400).send(error));
      }
    } else {
      res.send(Object.assign({}, { "@iot.id": thing._id }, thing.toObject(), { "Locations@iot.navigationLink": "thing without any location created" }));
    }
  }, (error) => res.status(400).send(error));
});


app.get('/observations', (req, res) => {
  Observations.find().then((obs) => {
    res.send(obs);
  }, (error) => {
    res.status(400).send(error);
  });
});

app.get('/observations/:id', (req, res) => {
  var id = req.params.id;

  Observations.find({iot_id: id}).then((observations) => {
    if (!observations) {
      res.sendStatus(404);
    }
    res.send({ observations });
  })
  .catch((error) => {
    res.status(404).send(error);
  });
});

app.listen(3000, () => {
  console.log("Server up and running on port 3000");
});
