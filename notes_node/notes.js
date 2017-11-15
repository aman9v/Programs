// console.log('Starting notes.js');

const fs = require('fs');
// module.exports.age = 25;
// exports is an object on module property that is used to set properties
 // so that they could used outside the file anywhere that uses require().

var fetchNotes = () => {
  try {
    var noteString = fs.readFileSync('notes.json');
    return JSON.parse(noteString);
  } catch (error) {
      return [];
  }
};

var saveNotes = (notes) => {
    fs.writeFileSync('notes.json', JSON.stringify(notes)); // doesn't need a callback function
};


// ES6 arrow function doesn't bind the this keyword and the arguments array.
var addNote = (title, body) => {
  var notes = fetchNotes();
  var note = {
    title,
    body,
  };
  var duplicateNotes = notes.filter((note) => note.title === title);

  if (duplicateNotes.length == 0){
      notes.push(note);
      saveNotes(notes);
      return note;
  }
};

var getAll = () => {
  return fetchNotes();
};

var readNote = (title) => {
  var notes = fetchNotes();
  var allNotes = notes.filter((note) => note.title === title);
  return allNotes[0];
};

var deleteNote = (title) => {
  var notes = fetchNotes();
  var newNotes = notes.filter((note) => note.title !== title);
  saveNotes(newNotes);
  return notes.length !== newNotes.length;
};

var logNotes = (note) => {
  console.log(`Title: ${note.title}`);
  console.log(`Body: ${note.body}`);
};
module.exports = {
  addNote,// In ES6 we can do without ":" if property and value name are exactly the same
  getAll,
  readNote,
  deleteNote,
  logNotes
};
