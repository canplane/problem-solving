const _input = require('fs').readFileSync("/dev/stdin", "utf8").trim().split("\n");
let _input_idx = 0;
const input = () => _input[_input_idx++];

let msg = input();
for (let i = 0; i < msg.length; i += 10)
    console.log(msg.substring(i, i + 10));