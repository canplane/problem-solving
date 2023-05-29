const _input = require('fs').readFileSync("/dev/stdin", "utf8").trim().split("\n");
let _input_idx = 0;
const input = () => _input[_input_idx++];

let T = parseInt(input());
for (let i = 0; i < T; i++) {
    let [A, B] = input().split(" ").map(e => parseInt(e));
    console.log(`Case #${i + 1}: ${A} + ${B} = ${A + B}`);
}