const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

otherSolution();

function mySolution(){
	let input = [];

	rl.on('line', function (line) {
		input = line.split(' ');
	}).on('close', function () {
		console.log(input[0] + input[1]);
	});
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution(){
	//배열에 저장된 각 문자열을 일일이 더하는 것이 아니라
	//Array.prototype.join 메서드를 사용
	let input = [];

	rl.on('line', function (line){
		input = line.split(' ');
		console.log(input.join(''));
	});
}
