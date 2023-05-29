(() => {
    const _input = [];
    const input = () => _input.shift();

    const rl = require("readline").createInterface({ input: process.stdin, output: process.stdout });
    rl.on("line", line => _input.push(line));
    rl.on("close", () => { solution(input); process.exit(); });
})();

const solution = input => {
    let [A, B] = input().split(" ").map(e => parseInt(e));
    console.log(A + B);
}