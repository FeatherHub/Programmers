const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

mySolution();

function mySolution() {
	rl.on('line', function (line) {
		const [operand1, operand2] = line.split(' ').map(v => parseInt(v));

		const result = operand1 + operand2;

		console.log(`${operand1} + ${operand2} = ${result}`);
	});
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution1() {
	//map에 함수 표현식이 아니라 바로 함수를 전달함
	rl.on('line', function (line) {
		const [a, b] = line.split(' ').map(Number);
		
		//parseInt를 전달할 경우, parseInt의 두 번째 인수로 배열의 인덱스가 전달되어 의도와 다른 수로 변환될 수 있다.
		//const [a, b] = line.split(' ').map(parseInt);

		console.log(a, '+', b, '=', a + b);
	});
}