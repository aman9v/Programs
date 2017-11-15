/* jshint esversion:6 */
const {mongoose} = require('./db/mongoose.js');

var CourseSchema = new mongoose.Schema({
  course_name: {
    type: String,
    required: true,
    minlength: 1,
    trim: true
  },
  semester: {
    type: String,
    required: true,
    trim: true,
    minlength: 1
  }
});

var StudentSchema = new mongoose.Schema({
  name: {
    type: String,
    required: true,
    trim: true,
    minlength: 1
  },
  course_name: { type: mongoose.Schema.Types.String, ref: 'Course' },
});

var Course = mongoose.model('Course', CourseSchema);
var Student = mongoose.model('Student', StudentSchema);

var course1 = new Course({
  course_name: "Advanced SIP",
  semester: "Spring"
});

course1.save().then((course) => {
  console.log(course1);
  var student1 = new Student({
    name: "Ankur Shukla",
    course_name: course1.course_name
  });
  student1.save().then((student) => {
    console.log("Student saved:", student.course_name);
  }, (error) => {
    console.log("Error saving student");
  });
  var student2 = new Student({
    name: "Rajat Shinde",
    course_name: course1.course_name
  });
  student2.save().then((student) => {
    console.log("Student saved:", student.course_name);
  }, (error) => {
    console.log("Error saving student");
  });
}, (error) => {
  console.log(error);
});
