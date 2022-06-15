const rl = require("readline").createInterface({
    input: process.stdin,
    output: process.stdout,
});

rl.on("line", line => {
    input = line.split(" ").map(e => parseInt(e));
}).on("close", () => {
    main(input);
    process.exit();
});

const main = input => {
    const A = parseInt(input[0]);
    const B = parseInt(input[1]);
    console.log(A + B);
};