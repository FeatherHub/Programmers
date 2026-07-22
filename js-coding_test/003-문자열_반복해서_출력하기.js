const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

mySolution();

function mySolution() {
	let input = [];

	rl.on('line', function (line) {
		input = line.split(' ');

		console.log(input[0].repeat(input[1]));

	});
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution1() {
	//배열 디스트럭처링 할당을 사용
	rl.on('line', function(line) {
		const [text, number] = line.split(' ');
		console.log(text.repeat(number));
	});
}