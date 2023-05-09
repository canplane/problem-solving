const _input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let _input_idx = 0;
const input = () => _input[_input_idx++];

let n = parseInt(input());
let ans = 0;
while (n)
    ans += n--;
console.log(ans);