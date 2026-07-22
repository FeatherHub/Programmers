const result = otherSolution('');
console.log(result);

function mySolution(s) {
	let pCnt = 0, yCnt = 0;
	for (let char of s.toLowerCase()) {
		if (char === 'p') {
			++pCnt;
		}
		else if (char === 'y') {
			++yCnt;
		}
	}

	return pCnt === yCnt;
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution(s) {
	//정규식 응용
	//  global flag
	//  case-insensitive flag
	//  String.prototype.match
	//  match 함수에서 반환된 배열의 length 프로퍼티
	//  note: match 결과가 없으면 null을 반환한다.
	
	const matchP = /P/ig;
	const matchY = /Y/ig;

	return s.match(matchP)?.length === s.match(matchY)?.length;
}

/* 문제
Suppose that a string s consisting of both lower-case and upper-case letters is given. 
Write a function "solution" 
  to return True when the number of 'p' and 'y' in s are the same, 
  and return False otherwise. 
Note that when there is neither 'p' nor 'y', it should always return True. 
Also, when comparing the number of 'p' and 'y', lower-case and upper-case are not distinguished.

https://school.programmers.co.kr/learn/courses/30/lessons/12916
*/