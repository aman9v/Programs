const request = require('supertest'); // to test http routes
const expect = require('expect'); // to use assertions provided by expect()
var app = require('./server').app;

describe('Server Tests', () => {
  describe('#GET /', () => {
    // test that verifies if get request sends hello world.
    it('should return hello world response', (done) => {
      request(app)
        .get('/')
        .expect(200)
        .expect((res) => { // this callback will be called by supertest.
          expect(res.body).toInclude({ // supertest only supports toBe assertion from expect library
            error: 'Page not found',
          });
        }) //checks to see if the response from the app is Hello World
        .end(done) // does different things depending on what is passed to it
    });
  });
  describe('#GET /users', () => {
    it('should contain my user and status 200', (done) => {
      request(app)
        .get('/user')
        // .expect(200)
        .expect((res) => {
          expect(res.body).toInclude({
            name: "Vishi",
            age: 25,
          });
        })
        .expect(200, done) // marks the end of request
    });
  });
});

// failed assertions are passed to end() callback as error.
// To fail the test case, pass err to done
// .end(function (err, res) {
//   if (err) return done(err);
//   done();
// });
