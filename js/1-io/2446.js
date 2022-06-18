const _input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let _input_idx = 0;
const input = () => _input[_input_idx++];

let N = +input();
let msg = "";
for (let i = 1, b = true; i >= 1; b ? i++ : i--) {
    for (let j = 1; j <= i - 1; j++)
        msg += " ";
    for (let j = 1; j <= 2 * (N - i) + 1; j++)
        msg += "*";
    msg += "\n";
    if (i == N) b = !b;
}
console.log(msg);