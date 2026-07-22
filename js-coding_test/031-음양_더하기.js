
function mySolution(absolutes, signs) {
	const integers = absolutes.map((val, idx) =>
		val * (signs[idx] ? +1 : -1));

	let sum = 0;
	for (let i = 0; i < integers.length; ++i) {
		sum += integers[i];
	}

	return sum;
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution(absolutes, signs) {
	//배열 고차함수 reduce를 사용
	return absolutes.reduce((acc, val, idx) =>
		acc += val * (signs[idx] ? +1 : -1) , 0);
}

/* 문제
어떤 정수들이 있습니다. 
  이 정수들의 절댓값을 차례대로 담은 정수 배열 absolutes와 
  이 정수들의 부호를 차례대로 담은 불리언 배열 signs가 
매개변수로 주어집니다. 
실제 정수들의 합을 구하여 return 하도록 solution 함수를 완성해주세요.

https://school.programmers.co.kr/learn/courses/30/lessons/76501
*/