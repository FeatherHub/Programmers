function mySolution(numLog) {
	const controlMap = {
		'1': 'w', '-1': 's', '10': 'd', '-10': 'a',
	};

	const controlCharacters = [];

	numLog.reduce((prev, cur) => {
		const controlChar = controlMap[cur - prev];
		controlCharacters.push(controlChar);
		return cur;
	});

	return controlCharacters.join('');
	//note: 배열 join 시 undefined는 문자열 구성에서 제외된다.
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution(numLog) {
	//중간 결과를 누적하는 배열을 사용하지 않고
	//map을 사용해 바로 결과 배열을 만든다.

	const controlMap = {
		'1': 'w', '-1': 's', '10': 'd', '-10': 'a',
	};

	let prev = numLog[0];
	return numLog.slice(1).map((cur) => {
		const controlChar = controlMap[cur - prev];

		prev = cur;

		return controlChar;
	}).join('');
}

function otherSolution2(numLog) {
	//원본 배열과 위치가 1만큼 어긋나는 배열을 생성해서
	//위 방법의 prev와 cur을 표현한다.

	const resultToControl = {
		'1': 'w', '-1': 's', '10': 'd', '-10': 'a',
	};

	return numLog.slice(1).map((cur, idx) =>
		resultToControl[cur - numLog[idx]])
		.join('');

	/* 
	numLog => numLog[i]는 numLog.slice(1)[i]의 관계에서 prev를 표현한다.
		IDX  0 1 2 3 4 5
		ELEM A B C D E F  
	numLog.slice(1) => numLog.slice(1)[i]는 numLog[i]와의 관계에서 cur을 표현한다.
		IDX  0 1 2 3 4
		ELEM B C D E F
	*/
}

/* 문제
정수 배열 numLog가 주어집니다. 

처음에 numLog[0]에서 부터 시작해 "w", "a", "s", "d"로 이루어진 문자열을 입력으로 받아 순서대로 다음과 같은 조작을 했다고 합시다.
  "w" : 수에 1을 더한다.
  "s" : 수에 1을 뺀다.
  "d" : 수에 10을 더한다.
  "a" : 수에 10을 뺀다.
그리고 매번 조작을 할 때마다 결괏값을 기록한 정수 배열이 numLog입니다. 즉, numLog[i]는 numLog[0]로부터 총 i번의 조작을 가한 결과가 저장되어 있습니다.

주어진 정수 배열 numLog에 대해 
  조작을 위해 입력받은 문자열을 
return 하는 solution 함수를 완성해 주세요.

https://school.programmers.co.kr/learn/courses/30/lessons/181925
*/
