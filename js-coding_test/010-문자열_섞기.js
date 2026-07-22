const res = otherSolution("abcdef", "pqrstu");
console.log(res);

function mySolution(str1, str2) {
	const stringArray = [str1, str2];
	const resultStringArray = [];
	for(let strIdx = 0; strIdx < str1.length; ++strIdx) {
		for(let arrIdx = 0; arrIdx < stringArray.length; ++arrIdx) {
			resultStringArray.push(stringArray[arrIdx][strIdx]);
		}
	}

	return resultStringArray.join('');
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution(str1, str2) {
	//각 문자열에서 문자를 하나씩 꺼낸다는 개념을 사용
	const str1Array = [...str1];
	const str2Array = [...str2];
	const resultStrArray = [];

	while(str1Array.length !== 0) {
		resultStrArray.push(str1Array.shift(), str2Array.shift());
	}

	return resultStrArray.join('');
}