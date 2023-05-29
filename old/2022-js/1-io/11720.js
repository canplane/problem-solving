const _input = require('fs').readFileSync("/dev/stdin", "utf8").trim().split("\n");
let _input_idx = 0;
const input = () => _input[_input_idx++];

let N = parseInt(input());
let sum = 0;
let nums = input();
for (let i = 0; i < nums.length; i++)
    sum += +nums[i];
console.log(sum);