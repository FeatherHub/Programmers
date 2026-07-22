//아이디어:
//  단어의 첫글자가 알파벳인 경우와 숫자인 경우로 나누어서 처리한다
//  연속된 공백 처리에 유의한다

//아이디어 구현
//1. 문자열을 공백을 기준으로 단어들로 나눈다
//2. 단어가 빈문자열인지 검사한다. *연속된 공백의 경우 빈문자열 발생
//  2-1. 단어가 공백이면 공백을 리턴한다.
//  2-2. 단어가 공백이 아니면 다음 절차를 수행한다.
//    3.단어의 첫문자가 알파벳인지 검사한다
//      3-1  알파벳인 경우 Aaaa 형태로 만든다
//      3-2  숫자인 경우 1aaa 형태로 만든다
//4. 각 단어를 공백으로 연결해서 합친다

function solution(s) {
  const words = s.split(' ');
  const jadenCaseWords = words.map(word => {
    const firstChar = word[0];
    const restChars = word.slice(1);

    if (word === '') {
      return word;
    }
    if (isNum(firstChar)) {
      return firstChar + restChars.toLowerCase();
    } else {
      return firstChar.toUpperCase() + restChars.toLowerCase();
    }
  });

  return jadenCaseWords.join(' ');

  function isNum(character) {
    //1. character를 숫자로 변환 시도
    //  2-1 변환 성공시 isNaN은 false 반환
    //  2-2 변환 실패시 isNaN은 true 반환
    return !Number.isNaN(+character);
  }
}

/* 문제: JadenCase 문자열 만들기 (*는 제가 표시했습니다.)
JadenCase란 모든 *단어*의 *첫 문자*가 대문자이고, 그 외의 알파벳은 소문자인 문자열입니다. 
  *단*, 첫 문자가 알파벳이 아닐 때에는 이어지는 알파벳은 소문자로 쓰면 됩니다. (첫 번째 입출력 예 참고)
문자열 s가 주어졌을 때, s를 JadenCase로 바꾼 문자열을 리턴하는 함수, solution을 완성해주세요.

제한 조건
  s는 길이 1 이상 200 이하인 문자열입니다.
  s는 알파벳과 숫자, 공백문자(" ")로 이루어져 있습니다.
    숫자는 단어의 *첫 문자로만* 나옵니다.
    숫자로만 이루어진 단어는 없습니다.
    *공백문자가 연속*해서 나올 수 있습니다.
*/
