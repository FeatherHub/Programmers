const readline = require('readline');

const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

let input = [];

rl.on('line', function (line) {
	input.push(line);
}).on('close', function () {
	let str = input[0];
	console.log(str);
});

/*****************
  다른 분들의 풀이
******************/
function otherSolution1() {
	//rl변수를 선언하지 않고 createInterface반환값에 바로 이벤트헨들러 등록하는 방법
	readline.createInterface({
		input: process.stdin,
		output: process.stdout
	}).on('line', function (line) { })
		.on('close', function () { });
}

function otherSolution2() {
	//이벤트헨들러의 콜백함수에 console.log 함수를 바로 등록하는 방법
	readline.createInterface({
		input: process.stdin,
		output: process.stdout
	}).on('line', console.log);
}