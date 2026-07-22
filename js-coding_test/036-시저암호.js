const shiftCharacter = (function () {
  const CHAR_A_CODE_POINT = 'A'.codePointAt(0);
  const CHAR_a_CODE_POINT = 'a'.codePointAt(0);

  function shiftCharacter(char, offset) {
    const baseCodePoint = isUpperCase(char)
      ? CHAR_A_CODE_POINT
      : CHAR_a_CODE_POINT;

    //map to range [0, 25]
    const normalized = char.codePointAt(0) - baseCodePoint;

    //shift character
    const offsetApplied = (normalized + offset) % 26;

    //recover case
    return String.fromCodePoint(offsetApplied + baseCodePoint);
  }

  function isUpperCase(char) {
    return char === char.toUpperCase();
  }

  return shiftCharacter;
})();

function solution(s, n) {
  const caesarEncodedChars = [...s].map(c =>
    c === ' ' ? c : shiftCharacter(c, n)
  );

  return caesarEncodedChars.join('');
}

const result = solution('abcdxyzXYZ', 1);
console.log(result);

/* 처음 실수한 부분
	//map to range [1, 26] <== 실수
	let normalizedCharCode =
		char.codePointAt(0) - caseBaseCharCode + 1;

	//caesar encode
	normalizedCharCode =
		(normalizedCharCode + offset) % 26;

	//recover case 
	return String.fromCodePoint(
		normalizedCharCode + caseBaseCharCode - 1);
*/

/* 문제: 시저 암호
어떤 문장의 각 알파벳을 일정한 거리만큼 밀어서 다른 알파벳으로 바꾸는  암호화 방식을 시저 암호라고 합니다. 
예를 들어 "AB"는 1만큼 밀면 "BC"가 되고, 3만큼 밀면 "DE"가 됩니다. 
"z"는 1만큼 밀면 "a"가 됩니다. 
문자열 s와 거리 n을 입력받아 s를 n만큼 민 암호문을 만드는 함수, solution을 완성해 보세요.

https://school.programmers.co.kr/learn/courses/30/lessons/12926
*/
