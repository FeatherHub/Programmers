function solution(n) {
  const collatz_array = [];

  let current = n;

  while (current !== 1) {
    collatz_array.push(current);

    let next;
    if (current % 2 === 0) {
      next = current / 2;
    } else {
      next = current * 3 + 1;
    }
    current = next;
  }
  collatz_array.push(current);
  return collatz_array;
}

function solution_2(n) {
  const collatz_array = [];

  let current = n;
  while (current !== 1) {
    collatz_array.push(current);
    current = next(current);
  }
  collatz_array.push(current);
  return collatz_array;

  function next(current) {
    return current % 2 === 0 ? current / 2 : current * 3 + 1;
  }
}

/*****************
다른 분들의 풀이
******************/
function other_solution(n) {
  //generator를 배열 컨텍스트에서 spread하면
  //IteratorResult의 done이 false가 될 때까지
  //generator의 next를 반복호출하고
  //IteratorResult의 value를 배열에 추가한다.
  return [...collatz(n)];

  function* collatz(n) {
    let current = n;
    yield current;
    while (current !== 1) {
      current = next(current);
      yield current;
    }
  }

  function next(current) {
    return current % 2 === 0 ? current / 2 : current * 3 + 1;
  }
}

/*
모든 자연수 x에 대해서 현재 값이 x이면
  x가 짝수일 때는 2로 나누고, 
  x가 홀수일 때는 3 * x + 1로 
바꾸는 계산을 계속해서 반복하면 
언젠가는 반드시 x가 1이 되는지 묻는 문제를 콜라츠 문제라고 부릅니다.

그리고 위 과정에서 거쳐간 모든 수를 기록한 수열을 콜라츠 수열이라고 부릅니다.

계산 결과 1,000 보다 작거나 같은 수에 대해서는 전부 언젠가 1에 도달한다는 것이 알려져 있습니다.

임의의 1,000 보다 작거나 같은 양의 정수 n이 주어질 때 
초기값이 n인 콜라츠 수열을 return 하는 solution 함수를 완성해 주세요.
 */

/*
  n=5

  5: 3 * 5 + 1 => 16
  16: 16 /2 => 8
  8: 8 / 2 => 4
  4: 4 / 2 => 2
  2: 2 / 2 => 1
*/
