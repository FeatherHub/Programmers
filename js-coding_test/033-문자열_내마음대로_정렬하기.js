function mySolution(strings, n) {
	return strings
		.map(string => { return { key: string[n], data: string }; })
		.sort((keyedString1, keyedString2) => {
			const {key: key1, data: string1} = keyedString1;
			const {key: key2, data: string2} = keyedString2;
			if (key1 === key2) {
				return string1 >= string2 ? 1 : -1;
			} else {
				return key1 > key2 ? 1 : -1;
			}
		})
		.map(({ data }) => data);
	/* 풀이 설명
   1. 문자열 배열로부터 각 문자열 원소의 n번째 문자를 key로 각 문자열을 data로 가지는 객체 배열을 map 메서드를 통해 만든다.
	2. 객체 배열을 대상으로 sort를 진행한다.
	3. 객체 배열에서 원래 문자열 배열의 원소인 data를 추출한다.
	*/
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution(strings, n) {
	/*
	1. sort 메서드의 compareFn만을 사용
	2. String.prototype.localeCompare 메서드 사용
	  note: locale
	*/
	return strings.sort((str1, str2) => {
		return str1[n] === str2[n] ?
				str1.localeCompare(str2) :
				str1[n].localeCompare(str2[n]);
	});
}

/* 문제: 문자열 내 마음대로 정렬하기
문자열로 구성된 리스트 strings와, 정수 n이 주어졌을 때, 
각 문자열의 인덱스 n번째 글자를 기준으로 오름차순 정렬하려 합니다. 
예를 들어 strings가 ["sun", "bed", "car"]이고 n이 1이면 각 단어의 인덱스 1의 문자 "u", "e", "a"로 strings를 정렬합니다.

인덱스 1의 문자가 같은 문자열이 여럿 일 경우, 사전순으로 앞선 문자열이 앞쪽에 위치합니다.

https://school.programmers.co.kr/learn/courses/30/lessons/12915
*/