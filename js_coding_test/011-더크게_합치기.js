const result = otherSolution2(410, 50);
console.log(result);

function mySolution(a, b) {
	const ab = concatNumber(a, b);
	const ba = concatNumber(b, a);

	return ab >= ba ? ab : ba;

	function concatNumber(first, second) {
		return parseInt(String(first) + String(second));
	}
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution(a, b) {
	//1. 삼항연산자 대신 Math.max 함수 사용
	//2. 명시적 형변환 대신 암묵적 형변환  +(), +"" 사용
	return Math.max(+("" + a + b), +("" + b + a));
}

function otherSolution2(a, b) {
	//1. 함수선언 대신 화살표 함수 사용
	//2. 형변환 대신 템플릿 리터럴 사용
	const concatNumber = (first, second) => +`${first}${second}`;

	return Math.max(concatNumber(a, b), concatNumber(b, a));
}