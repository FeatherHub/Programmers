const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

let input = [];

rl.on('line', function (line) {
	input = line.split(' ');
}).on('close', function () {
	console.log(`a = ${Number(input[0])}\nb = ${Number(input[1])}`);
});

/*****************
  다른 분들의 풀이
******************/
function otherSolution1() {
	//배열 디스트럭처링 할당 문법을 사용
	rl.on('line', function (line) {
		const [a, b] = line.split(' ');
		console.log(`a = ${a}\nb = ${b}`);
	});
}

function otherSolution2() {
	//더 많은 입력값에 대응할 수 있도록 더 일반적인 해답을 제시
	let i = 0;
	rl.on('line', function (line) {
		for (const value of line.split(' ')) {
			console.log(String.fromCharCode(97 + i) + " = " + Number(value));
			++i;
		}
	});
}

function otherSolution3() {
	//map 고차함수를 사용해서 String배열을 Number배열로 변환 후 출력부에 전달
	rl.on('line', function (line) {
		const numbers = line.split(' ').map(token => parseInt(token));
		
		console.log(`a = ${numbers[0]}\nb = ${numbers[0]}`);
	})
}
