const _input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");
let _input_idx = 0;
const input = () => _input[_input_idx++];

const DAYS = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];

let [x, y] = input().split(" ").map(e => +e);
console.log(DAYS[new Date("2007", x - 1, y).getDay()]);
