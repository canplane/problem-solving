let N = +require("fs").readFileSync("/dev/stdin");

let output = [];
for (let i = 1; i < 10; i++)
    output.push(`${N} * ${i} = ${N * i}`);
console.log(output.join("\n"));