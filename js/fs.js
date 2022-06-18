// boj.kr/1000

const input = (() => {
    let _input = require("fs").readFileSync("/dev/stdin").toString(),
        _idx = 0;
    _input = _input.trim().split("\n");
    return () => _input[_idx++];
})();

let [A, B] = input().split(" ").map(e => +e);
console.log(A + B);
