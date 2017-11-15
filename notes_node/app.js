// console.log("Starting app.js");

// require to load in modules inside a node app. Also useful for leading the
// Using 3rd party modules provided by npm.
// We define the packages to use in the applicaito inside the package.json file
const fs = require('fs');
const _ = require('lodash');
const yargs = require('yargs');

const notes = require('./notes.js'); // now notes have a property called age after using exports.

const titleOptions = {
  describe: "main title",
  demand: true,
  alias: 't',
}
const bodyOptions = {
  describe: "body title",
  demand: true,
  alias: 'b',
}
const argv = yargs
    .command('add', 'Add a new Note', {
     title: titleOptions,
     body: bodyOptions,
    })
    .command('list', 'List all notes', {
      title: titleOptions
    })
    .command('remove', 'Remove a note', {
      title: titleOptions,
    })
    .help()
    .argv;
var command = argv._[0];
// console.log('Command:',command);
// console.log('Yargs:', argv);

if (command === 'add'){
  var note = notes.addNote(argv.title, argv.body);
  if (note){
    console.log('Note was returned');
    console.log('--');
    notes.logNotes(note);
  }else {
    console.log("There was some error");
  }
}else if (command === 'list'){
  var allNotes = notes.getAll();
  var notesLength = '';
  if (allNotes.length == 1){
    notesLength += "note";
  }  else {
    notesLength += "notes"
  }
  console.log(`Printing ${allNotes.length} ${notesLength}`);
  allNotes.forEach((note) => notes.logNotes(note));
} else if (command === 'read'){
    var note = notes.readNote(argv.title);
    if(note){
      console.log('Note reading successful');
      notes.logNotes(note);
    }else {
      console.log('No note found');
    }
} else if (command === 'remove'){
  var isDeleted = notes.deleteNote(argv.title);
  var message = isDeleted ? `${argv.title} Deleted` : `Something went wrong`;
  console.log(message);
} else {
  console.log('Command not recognized');
}
