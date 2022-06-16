const _input = require('fs').readFileSync("/dev/stdin", "utf8").trim().split("\n");
let _input_idx = 0;
const input = () => _input[_input_idx++];

input();
let sum = input().split("").reduce((acc, e) => acc + +e, 0);
console.log(sum);