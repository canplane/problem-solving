const input = (() => {
    let _input = require("fs").readFileSync("/dev/stdin").toString(),
        _idx = 0;
    _input = _input.trim().split("\n");
    return () => _input[_idx++];
})();

let N = +input();
let memo = new Array(N + 1).fill(0);

for (let i = 2; i <= N; i++) {
    memo[i] = memo[i - 1];
    if (i % 3 === 0 && memo[i / 3] < memo[i])
        memo[i] = memo[i / 3];
    if (i % 2 === 0 && memo[i / 2] < memo[i])
        memo[i] = memo[i / 2];
    memo[i]++;
}

console.log(memo[N]);