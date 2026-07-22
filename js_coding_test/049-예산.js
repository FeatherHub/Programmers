// 아이디어: 가장 적은 예산을 지원한 부서부터 지원해준다.
// 구현
//   부서별 신청예산 배열을 오름차순으로 정렬한다.
//   앞에서부터 배열의 원소를 읽어 총예산을 차감한다.
//     만약 총예산이 음수이면 현재 부서를 포함해서
//     더 이상 부서에 예산을 지원할 수 없다.
//     만약 총예산이 음수가 아니면 현재 부서를 지원할 수 있다

function solution(depBudgets, totalBudget) {
  const ascDepBudgets = depBudgets.sort((a, b) => a - b);
  let depCount = 0;
  for (const depBudget of ascDepBudgets) {
    totalBudget -= depBudget;
    if (totalBudget < 0) {
      break;
    }
    ++depCount;
  }
  return depCount;
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution(d, budget) {
  //지원가능한 부서 개수를 세기 위한 depCount를 사용하지 않고
  //배열의 현재 인덱스로부터 지원가능한 부서의 개수를 이끌어낸다
  d.sort((a, b) => a - b);

  let i = 0;
  while (i < d.length) {
    budget -= d[i];
    if (budget < 0) {
      break;
    }
    ++i;
  }
  return i;
}

/* 문제: 예산
S사에서는 각 부서에 필요한 물품을 지원해 주기 위해 부서별로 물품을 구매하는데 필요한 금액을 조사했습니다. 
그러나, *전체 예산*이 정해져 있기 때문에 모든 부서의 물품을 구매해 줄 수는 없습니다. 
그래서 *최대한 많은 부서*의 물품을 구매해 줄 수 있도록 하려고 합니다.

물품을 구매해 줄 때는 각 부서가 *신청한 금액만큼을 모두 지원*해 줘야 합니다.
  예를 들어 1,000원을 신청한 부서에는 정확히 1,000원을 지원해야 하며, 1,000원보다 적은 금액을 지원해 줄 수는 없습니다.

부서별로 신청한 금액이 들어있는 배열 d와 예산 budget이 *매개변수*로 주어질 때, 
최대 몇 개의 부서에 물품을 지원할 수 있는지 *return* 하도록 
solution 함수를 완성해주세요.

https://school.programmers.co.kr/learn/courses/30/lessons/12982
*/
