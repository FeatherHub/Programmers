const result = mySolution(10, 20, true);
console.log(result);

function mySolution(a, b, flag) {
	const expressionMap = {
		true: (a, b) => a + b,
		false: (a, b) => a - b,
	};

	return expressionMap[flag](a, b);
}

function otherSolution(a, b, flag) {
	//삼항 연산자 활용
	//boolean값이 주어지는 상황에서 간결한 표현이 가능하다.
	return flag ? a + b : a - b;
}

/* 문제
두 정수 a, b와 boolean 변수 flag가 매개변수로 주어질 때, 
  flag가 true면 a + b를 
  false면 a - b를 
return 하는 solution 함수를 작성해 주세요.

https://school.programmers.co.kr/learn/courses/30/lessons/181933
*/