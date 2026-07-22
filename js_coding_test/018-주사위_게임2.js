const result = otherSolution(2, 2, 2);
console.log(result);

function mySolution(a, b, c) {
	const diceArr = [a, b, c];
	const sameCnt = countSame(diceArr);

	console.log('sameCnt:', sameCnt);
	let sumArr = [];
	for (let exponent = 1; exponent <= sameCnt; ++exponent) {
		sumArr.push(diceArr.reduce((acc, cur) =>
			acc + Math.pow(cur, exponent), 0));
	}

	return sumArr.reduce((acc, cur) => acc *= cur);

	//원소개 3개일 때에만 적용되는 한정적인 함수
	function countSame(arr) {
		const sameCntArr = Array(arr.length).fill(0);

		arr.forEach((val1, idx1) => {
			arr.forEach((val2) => {
				if (val1 === val2) {
					++sameCntArr[idx1];
				}
			})
		});

		return sameCntArr.reduce((max, cur) => Math.max(max, cur));
	}
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution(a, b, c) {
	//1. 각 항의 제곱을 더한 결과를 배열에 모은 후 곱하지 않고
	//더한 즉시 기초값 1에 곱하기 시작하면서 누적한다.
	//2. 중복된 값의 개수를 구하기 위해 set 자료구조를 활용한다. 

	const sameCnt = countSame([a, b, c]);

	console.log(sameCnt);
	let result = 1;
	for(let exp = 1; exp <= sameCnt; ++exp) {
		result *= Math.pow(a, exp) + Math.pow(b, exp) + Math.pow(c, exp);
	}

	return result;

	//원소개 3개일 때에만 적용되는 한정적인 함수
	function countSame(arr) {
		return arr.length - (new Set(arr).size) + 1;
	}
}

/* 문제
1부터 6까지 숫자가 적힌 주사위가 세 개 있습니다. 세 주사위를 굴렸을 때 나온 숫자를 각각 a, b, c라고 했을 때 얻는 점수는 다음과 같습니다.
  세 숫자가 모두 다르다면 a + b + c 점을 얻습니다.  
  세 숫자 중 어느 두 숫자는 같고 나머지 다른 숫자는 다르다면 (a + b + c) × (a^2 + b^2 + c^2 )점을 얻습니다.
  세 숫자가 모두 같다면 (a + b + c) × (a^2 + b^2 + c^2 ) × (a^3 + b^3 + c^3 )점을 얻습니다.
세 정수 a, b, c가 매개변수로 주어질 때, 얻는 점수를 return 하는 solution 함수를 작성해 주세요.
*/
