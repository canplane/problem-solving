const rl = require("readline").createInterface({ input: process.stdin, output: process.stdout, });

const _input = [];
let _input_cursor = 0;
const input = () => _input[_input_cursor++];

rl.on("line", line => {
    _input.push(line);
}).on("close", () => {
    main();
    process.exit();
});

const main = () => {
    let T = parseInt(input());
    for (let i = 0; i < T; i++) {
        let [A, B] = input().split(" ").map(e => parseInt(e));
        console.log(A + B);
    }
};