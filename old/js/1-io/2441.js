const _input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let _input_idx = 0;
const input = () => _input[_input_idx++];

let N = +input();
let msg = "";
for (let i = N; i >= 1; i--) {
    for (let j = 1; j <= N - i; j++)
        msg += " ";
    for (let j = 1; j <= i; j++)
        msg += "*";
    msg += "\n";
}
console.log(msg);