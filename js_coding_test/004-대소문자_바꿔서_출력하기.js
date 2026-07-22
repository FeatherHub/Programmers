const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

mySolution();

function mySolution() {
	rl.on('line', function (line) {
		//배열고차함수 map을 사용하기 위해 유사배열인 문자열을 배열로 변환
		const charArr = [...line];
		const switchedCharArr = charArr.map(switchCase);
		//배열을 다시 문자열로 변환
		const switchedCharStr = switchedCharArr.join('')
		console.log(switchedCharStr);
	});

	function switchCase(char) {
		const codePoint = char.codePointAt(0);
		if (isLowerCase(codePoint)) {
			return toUpperCase(codePoint);
		} else if (isUpperCase(codePoint)) {
			return toLowerCase(codePoint);
		} else {
			return char;
		}
	}

	function isLowerCase(codePoint) {
		return codePoint >= 97 && codePoint <= 122;
	}

	function isUpperCase(codePoint) {
		return codePoint >= 65 && codePoint <= 90;
	}

	function toUpperCase(codePoint) {
		return String.fromCodePoint(codePoint - 32);
	}

	function toLowerCase(codePoint) {
		return String.fromCodePoint(codePoint + 32);
	}
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution1() {
	rl.on('line', function (line) {
		const buffer = [];
		//String.prototype.toUpperCase 메서드를 사용하고
		//반환값이 자신과 같다면 자신이 대문자라는 사실을 이용
		for(const c of line) {
			if(c === c.toUpperCase()) {
				buffer.push(c.toLowerCase());
			}
			else {
				buffer.push(c.toUpperCase());
			}
		}
		console.log(buffer.join(''));
	});
}

function otherSolution2() {
	//문자열의 각 문자를 소문자를 인식하는 정규식에 test하는 방식
	rl.on('line', function(line) {
		const isLowerCase = /[a-z]/;
		
		const switchedArr = [...line].map(char => 
			isLowerCase.test(char) ? char.toUpperCase() : char.toLowerCase()
		);

		console.log(switchedArr.join(''));
	});
}