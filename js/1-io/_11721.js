const _input = require('fs').readFileSync("/dev/stdin", "utf8").trim().split("\n");
let _input_idx = 0;
const input = () => _input[_input_idx++];

let msg = input();
while (msg.length) {
    let arr = msg.split("");
    console.log(arr.splice(0, 10).join(""));
    msg = arr.join("");
}
