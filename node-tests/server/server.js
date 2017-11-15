const express = require('express');

var app = express();

app.get('/', (req, res) => {
  res.status(200).send({
    error: 'Page not found',
    name: "Todo App v1.0",
  });
});

app.get('/user', (req, res) => {
  res.status(200).send([{
    name: "Vishi",
    age: 25,
  }, {
    name: 'Aman',
    age: 25,
  }])
})

app.listen(3000);
module.exports.app = app;
