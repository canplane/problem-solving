const _input = require('fs').readFileSync("/dev/stdin", "utf8").split("\n");
let _input_idx = 0;
const input = () => _input[_input_idx++];

let line;
while ((line = input()) !== undefined) {
    console.log(line);
}