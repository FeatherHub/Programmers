function solution(phone_number) {
  const pnum_arr = [...phone_number];
  const alter_count = phone_number.length - 4;

  //0번째 인덱스부터 alter_count 개수만큼 '*'로 바꾼다.
  pnum_arr.splice(0, alter_count, ...'*'.repeat(alter_count));

  return pnum_arr.join('');
}
//min time:0.04ms max time: 0.06ms

function solution2(phone_number) {
  //for문 활용
  let hidden_phone_number = '';
  const number_start_idx = phone_number.length - 4;
  for (let i = 0; i < phone_number.length; ++i) {
    hidden_phone_number +=
      i < number_start_idx ? '*' : phone_number[i];
  }

  return hidden_phone_number;
}
//min time:0.04ms max time: 0.06ms

/*****************
  다른 분들의 풀이
******************/
function otherSolution1(phone_number) {
  //slice 메서드를 활용
  //아이디어
  //1. * 알맞은 개수만큼 생성
  //2. 문자열 뒤에서부터 문자 4개 읽기
  //3. 두 부분을 합친 후 반환
  return '*'.repeat(phone_number.length - 4) + phone_number.slice(-4);
}
//min time:0.03ms max time: 0.03ms

function otherSolution2(phone_number) {
  //fill 메서드를 활용
  //아이디어
  //1. 배열의 앞을 *로 채우기
  //2. 반환
  return [...phone_number]
    .fill('*', 0, phone_number.length - 4)
    .join('');
}
//min time:0.03ms max time: 0.03ms

//퍼포먼스 차이에 대한 잠정적 결론
//  런타임에 파싱되는 언어의 경우
//  내장함수를 사용하는 편이 성능상 더 좋을 수 있다.

/* 문제: 핸드폰 번호 가리기 
프로그래머스 모바일은 개인정보 보호를 위해 고지서를 보낼 때 고객들의 *전화번호의 일부*를 가립니다. 
  => 집합과 부분집합 / 배열과 부분배열 개념

전화번호가 문자열 phone_number로 주어졌을 때, 전화번호의 뒷 4자리를 제외한 나머지 숫자를 전부 *으로 가린 문자열을 리턴하는 함수, solution을 완성해주세요.

input             output
"01033334444" =>  "*******4444"

https://school.programmers.co.kr/learn/courses/30/lessons/12948
*/
