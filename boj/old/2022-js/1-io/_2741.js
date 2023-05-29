let N = +require("fs").readFileSync("/dev/stdin");

let output = "";    // 시간 초과
for (let i = 1; i <= N; i++)
    output += i + "\n";
console.log(output);