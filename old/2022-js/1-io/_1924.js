const _input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let _input_idx = 0;
const input = () => _input[_input_idx++];

const DATES = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
const DAYS = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"];

let [x, y] = input().split(" ").map(e => +e);

let diff = 0;
for (let i = 1; i < x; i++)
    diff += DATES[i];
diff += (y - 1);

console.log(DAYS[diff % 7]);