function solution(l, r) {
  const containsOnly0or5 = createRange(l, r + 1)
    .map(String)
    .filter(val =>
      [...val].every(char => char === '0' || char === '5')
    )
    .map(Number);

  return containsOnly0or5.length ? containsOnly0or5 : [-1];

  /**
    @param from: inclusive
    @param to: exclusive

    creates an number array [from, from+1, ... to-1]
  */
  function createRange(from, to) {
    from = Number.parseInt(from);
    to = Number.parseInt(to);

    [from, to].forEach(parseResult => {
      if (Number.isNaN(parseResult)) {
        throw TypeError(
          '"from" and "to" must be number or convertable to number'
        );
      }
    });

    if (from > to) {
      throw RangeError(
        `"to" must not be less than "from". from:${from} to:$${to}`
      );
    }

    return [...Array(to - from + 1)].map((_, idx) => idx + from);
  }
}

/* 문제: https://school.programmers.co.kr/learn/courses/30/lessons/181921

정수 l과 r이 주어졌을 때, l 이상 r이하의 정수 중에서 숫자 "0"과 "5"로만 이루어진 모든 정수를 오름차순으로 저장한 배열을 return 하는 solution 함수를 완성해 주세요.

만약 그러한 정수가 없다면, -1이 담긴 배열을 return 합니다.

*/
