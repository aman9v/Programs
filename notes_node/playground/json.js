// var obj = {
//   name: "Aman",
// };
//
// var stringObj = JSON.stringify(obj);
// console.log(typeof stringObj);
// console.log(stringObj);
//
// var personString = '{"name": "Aman", "age": 25}';
// var person = JSON.parse(personString);
// console.log(typeof person);
// console.log(person.age, person.name);

const fs = require('fs');

var originalNote = {
  title: 'Some title',
  body: 'Some body',
};

var originalNoteString = JSON.stringify(originalNote);
fs.writeFileSync('notes.json', originalNoteString);

var noteString = fs.readFileSync('notes.json');

var noteObj = JSON.parse(noteString);
console.log(typeof noteObj);
console.log(noteObj.title, noteObj.body);
