const _input = require('fs').readFileSync("/dev/stdin", "utf8").trim().split("\n");
let _input_idx = 0;
const input = () => _input[_input_idx++];

while (true) {
    let [A, B] = input().split(" ").map(e => parseInt(e));
    if (A === 0 && B === 0) break;
    console.log(A + B);
}