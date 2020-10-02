let { greet } = require('../build/Release/greet.node');

let message = greet("Boris Dering");

console.log(message);