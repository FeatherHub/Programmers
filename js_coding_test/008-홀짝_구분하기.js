const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

mySolution();

function mySolution() {
	rl.on('line', function (line) {
		const number = Number(line);
		const isEven = n => n % 2 === 0;
		let resultString = `${number} is `;
		if (isEven(number)) {
			resultString += "even";
		} else {
			resultString += "odd";
		}
		console.log(resultString);
	});
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution() {
	//1. 수를 저장하는 변수를 사용하지 않음
	//2. 삼항연산자 사용
	//3. 결과문장을 컴포넌트 별로 조립
	rl.on('line', (line)=>{
		const result = Number(line) % 2 === 0 ? 'even' : 'odd';

		console.log(line, 'is', result);
	});
}