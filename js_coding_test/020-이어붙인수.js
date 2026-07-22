function mySolution(num_list) {
	const oddNumbers = num_list.filter(num => num % 2);
	const evenNumbers = num_list.filter(num => !(num % 2));

	const joinedOddNumbers = +oddNumbers.join('');
	const joinedEvenNumbers = +evenNumbers.join('');

	return joinedOddNumbers + joinedEvenNumbers;
}

function mySolution2(num_list) {
	//배열을 한 번만 스캔하는 방식
	const oddNumbers = [];
	const evenNumbers = [];

	num_list.forEach(num => {
		if(num % 2) {
			oddNumbers.push(num);
		} else {
			evenNumbers.push(num);
		}
	});

	return +oddNumbers.join('') + +evenNumbers.join('');
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution(num_list) {
	//reduce의 초기값, 누적값, 반환값에 객체를 적용
	//객체 프로퍼티를 통해 두 개 이상의 reduce 결과값을 만들 수 있다
	const {odds, evens} = num_list.reduce(({odds, evens}, curNum) => {
		curNum % 2 ? odds.push(curNum) : evens.push(curNum);
		return { odds, evens };
	}, {odds: [], evens: []});

	return +odds.join('') + +evens.join('');
}

/* 문제
정수가 담긴 리스트 num_list가 주어집니다. 
  num_list의 홀수만 순서대로 이어 붙인 수와 
  짝수만 순서대로 이어 붙인 수
	 의 합을 
return하도록 solution 함수를 완성해주세요.

https://school.programmers.co.kr/learn/courses/30/lessons/181928
*/