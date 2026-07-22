const result = mySolution2(5);
console.log(result);

function mySolution(n) {
	const isEven = n => n % 2 === 0;
	let result = 0;
	if (isEven(n)) {
		for (let i = 2; i <= n; ++i) {
			if (isEven(i)) {
				result += i ** 2;
			}
		}
	} else {
		for (let i = 1; i <= n; ++i) {
			if (!isEven(i)) {
				result += i;
			}
		}
	}
	return result;
}

function mySolution2(n) {
	let result = 0;

	const isEven = n => n % 2 === 0;
	const isOdd = n => !isEven(n);
	const range = Array.from({ length: n + 1 }, (_, i) => i);

	//각 경우의 계산식을 좀 더 선언적으로 표현
	if (isEven(n)) {
		result = range.filter(isEven)
			.reduce((acc, cur) => acc += cur ** 2, 0);
	} else {
		result = range.filter(isOdd)
			.reduce((acc, cur) => acc += cur, 0);
	}

	return result;
}

/* 문제
양의 정수 n이 매개변수로 주어질 때, 
  n이 홀수라면 
    n 이하의 홀수인 모든 양의 정수의 합을 return 하고 
  n이 짝수라면 
    n 이하의 짝수인 모든 양의 정수의 제곱의 합을 return 하는 
solution 함수를 작성해 주세요.

https://school.programmers.co.kr/learn/courses/30/lessons/181935
*/