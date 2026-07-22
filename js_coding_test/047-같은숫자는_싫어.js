/* 아이디어 & 구현방법
  연속이라는 말을 배열을 스캔하는 과정에서 이전값과 현재값이 같다는 말로 구체화한다.
    현재값이 이전값과 같으면 아무 작업도 하지 않고 다음 요소로 넘어간다.
    현재값이 이전값과 다르면 이전값을 결과배열에 푸시한다.
*/

//step1: 위에 서술된 말을 그대로 코드로 옮기고 예외처리만 추가
function solution_step1(arr) {
  const resultArr = [];
  let prev = arr[0];

  if (arr.length === 1) {
    resultArr.push(prev);
  } else {
    for (const cur of arr.slice(1)) {
      if (prev !== cur) {
        resultArr.push(prev);
      }
      prev = cur;
    }
    resultArr.push(arr.at(-1));
  }
  return resultArr;
}
//정확성 테스트 가장 오래걸린 시간: 0.16ms
//효율성 테스트 가장 오래걸린 시간: 71.39ms

//step2: 알고리즘 표현에서 예외처리를 회피하기 위해 구현방법 수정
//  현재값이 이전값과 다르면 현재값을 결과배열에 푸시
function solution_step2(arr) {
  const resultArr = [];

  let prev = arr[0];
  resultArr.push(prev);

  for (const cur of arr.slice(1)) {
    if (prev !== cur) {
      resultArr.push(cur);
    }
    prev = cur;
  }

  return resultArr;
}
//정확성 테스트 가장 오래걸린 시간: 0.20ms
//효율성 테스트 가장 오래걸린 시간: 64.99ms

//step3: 이전값이라는 개념을 사용하지 않고 연속된 값의 첫번째 값이라는 개념을 사용 => 연속된 값의 첫번째 값이라는 말을 스택의 탑으로 표현
//  현재값이 스택의 탑과 다르면 스택에 푸시
function solution_step3(arr) {
  const resultArr = [];

  for (const cur of arr) {
    if (cur !== resultArr[resultArr.length - 1]) {
      resultArr.push(cur);
    }
  }

  return resultArr;

  function top(arr) {
    return arr[arr.length - 1];
  }
}
//top 함수 미사용
//정확성 테스트 min/max: 1: 0.04ms 2: 0.04ms/ 1: 0.19ms 2: 0.22ms
//효율성 테스트 min/max: 1: 27.54ms 2: 50.16ms / 1: 53.16ms 2: 62.97ms

//top 함수 사용
//정확성 테스트 min/max: 1: 0.06ms 2: 0.05ms / 1: 0.21ms 2: 0.25ms
//효율성 테스트 min/max: 1: 28.82ms 2: 48.17ms / 1: 55.86ms 2: 54.84msms

/* 트러블 슈팅
스택의 탑으로서의 배열의 마지막 요소에 접근하기 위해 at 메서드 사용
if (resultArr.at(-1) !== cur) { // => 실패
      resultArr.push(cur);
}
*/
/* 해결: 프로그래머스 제공 'AI에게 물어보기' 결과
`at()` 메서드는 ES2021에서 도입되었기 때문에, ES2021 이전 버전의 JavaScript 환경에서는 해당 메서드를 지원하지 않습니다. 
따라서, 코드가 특정 환경에서만 작동하는 문제를 가지고 있을 수 있습니다.
*/

/* 문제: 같은 숫자는 싫어
배열 arr가 주어집니다. 배열 arr의 각 원소는 숫자 0부터 9까지로 이루어져 있습니다. 
이때, 배열 arr에서 *연속*적으로 나타나는 숫자는 하나만 남기고 전부 제거하려고 합니다. 단, 제거된 후 남은 수들을 반환할 때는 배열 arr의 원소들의 *순서를 유지*해야 합니다. 예를 들면,
arr = [1, 1, 3, 3, 0, 1, 1] 이면 [1, 3, 0, 1] 을 return 합니다.
arr = [4, 4, 4, 3, 3] 이면 [4, 3] 을 return 합니다.
배열 arr에서 연속적으로 나타나는 숫자는 제거하고 남은 수들을 return 하는 solution 함수를 완성해 주세요.

https://school.programmers.co.kr/learn/courses/30/lessons/12906
*/
