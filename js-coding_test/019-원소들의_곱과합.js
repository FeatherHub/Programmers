mySolution([1,2,3]);

function mySolution(num_list) {
	const allElemProduct = num_list.reduce((acc, cur) => acc *= cur);
	const allElemSumSquare = num_list.reduce((acc, cur) =>
		acc += cur) ** 2;

	return allElemProduct < allElemSumSquare ? 1 : 0;
}

/* 반복적으로 하는 실수
	const allElemSumSquare = num_list.reduce((acc, cur) 
	   => acc += cur) ** 2; 
		//SyntaxError: Unexpected token '=>'
		//ts(1200) line terminator not permitted before arrow
*/

/*****************
  다른 분들의 풀이
******************/
function otherSolution(num_list) {
	//한 번의 반복에 두 개의 계산을 모두 처리하는 방식
	let accMul = 1;
	let accSum = 0;

	for(const num of num_list) {
		accMul *= num;
		accSum += num;
	}

	return accMul < accSum ** 2 ? 1 : 0;
}

/* 문제
정수가 담긴 리스트 num_list가 주어질 때, 
  모든 원소들의 곱이 
  모든 원소들의 합의 제곱보다 
	 작으면 1을 
	 크면 0을 
return하도록 solution 함수를 완성해주세요.

https://school.programmers.co.kr/learn/courses/30/lessons/181929
*/