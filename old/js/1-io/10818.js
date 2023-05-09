const _input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let _input_idx = 0;
const input = () => _input[_input_idx++];

let N = +input();
let nums = input().split(" ").map(e => +e);

let min = nums[0], max = nums[0];
for (let i = 1; i < N; i++) {
    if (min > nums[i]) min = nums[i];
    if (max < nums[i]) max = nums[i];
}
console.log(min, max);