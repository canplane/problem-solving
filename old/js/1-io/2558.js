const _input = require('fs').readFileSync("/dev/stdin", "utf8").trim().split("\n");
let _input_idx = 0;
const input = () => _input[_input_idx++];

let A = parseInt(input()), B = parseInt(input());
console.log(A + B);
