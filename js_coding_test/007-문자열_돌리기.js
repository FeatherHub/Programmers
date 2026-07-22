const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

mySolution();

function mySolution() {
    rl.on('line', function (line) {
        [...line].forEach(c => console.log(c));
    });
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution(){
    rl.on('line', function(line) {
    //String.prototype.split 메서드를 사용해서 문자열로부터 각 문자의 배열을 만든다.    
        line.split('').forEach(c => console.log(c));
    })
}