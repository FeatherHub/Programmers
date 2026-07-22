function mySolution(n, control) {
	const controlMap = {
		w: 1, s: -1, d: 10, a: -10,
	};

	const controlResult = [...control]
		.map(controlCharacter => controlMap[controlCharacter])
		.reduce((acc, cur) => acc += cur);

	return n + controlResult;
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution(n, control) {
	//reduce에 map 중간 과정을 합칠 수 있다.
	//reduce에 초기값 n을 결합할 수 있다.
	const controlMap = {
		w: 1, s: -1, d: 10, a: -10,
	};

	return [...control].reduce((acc, controlChar) =>
		acc += controlMap[controlChar], n);
}

/* 문제
정수 n과 문자열 control이 주어집니다. 
control은 "w", "a", "s", "d"의 4개의 문자로 이루어져 있으며, 
control의 앞에서부터 순서대로 문자에 따라 n의 값을 바꿉니다.
  "w" : n이 1 커집니다.
  "s" : n이 1 작아집니다.
  "d" : n이 10 커집니다.
  "a" : n이 10 작아집니다.
위 규칙에 따라 n을 바꿨을 때 가장 마지막에 나오는 n의 값을 return 하는 solution 함수를 완성해 주세요.

https://school.programmers.co.kr/learn/courses/30/lessons/181926
*/