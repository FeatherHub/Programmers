//아이디어
// 정수 i가 가진 약수의 개수를 구하는 함수를 작성한다
// 제약조건을 적용해서 재료의 무게를 구한다

//구현
// 약수 개수 구하기
//   정수 n이 주어진다면 [2, floor(n/2)] 범위의 수로 n을 나눈다
//   나눈 나머지가 0이면 약수 개수를 증가시킨다.
//   n의 약수 [1, n] 2개를 약수 개수에 추가한다.
function solution_step1(number, limit, power) {
  const weaponPowerList = [];

  //for [1, knightNumber]
  for (let knightNumber = 1; knightNumber <= number; ++knightNumber) {
    const knightPower = getFactorCount(knightNumber);
    weaponPowerList.push(knightPower);
  }

  const materialWeight = weaponPowerList.reduce(
    (totalWeight, weaponDamage) => {
      if (weaponDamage > limit) {
        return totalWeight + power;
      } else {
        return totalWeight + weaponDamage;
      }
    },
    0
  );

  return materialWeight;

  function getFactorCount(integer) {
    if (integer <= 2) {
      return integer;
    }

    let factorCount = 2; //[1, n]
    const flooredHalf = Math.floor(integer / 2);
    //for [2, floor(n/2)]
    for (let i = 2; i <= flooredHalf; ++i) {
      if (integer % i === 0) {
        ++factorCount;
      }
    }

    return factorCount;
  }
}
//=====> 실패: 제한 시간 초과 3개
//min time: 0.04ms
//max time: 9596.24ms

//다음 단계:
//약수의 개수를 통해 기사의 공격력을 구할 때 약수의 개수가 limit 이상이 되면 더 이상 약수의 개수를 구하지 않고 바로 power를 반환한다

function solution_step2(number, limit, power) {
  const weaponPowerList = [];

  for (let knightNumber = 1; knightNumber <= number; ++knightNumber) {
    const knightPower = calcKnightPower(knightNumber, limit, power);
    weaponPowerList.push(knightPower);
  }

  const materialWeight = weaponPowerList.reduce(
    (totalWeight, weaponDamage) => totalWeight + weaponDamage,
    0
  );

  return materialWeight;

  function calcKnightPower(number, limit, power) {
    if (number <= 2) {
      return number; //2 <= limit <= 100
    }

    let factorCount = 2; //1과 자기자신 미리 카운트

    const flooredHalf = Math.floor(number / 2);
    //범위 [2, floor(knightNumber / 2)]
    for (let divider = 2; divider <= flooredHalf; ++divider) {
      if (number % divider === 0) {
        ++factorCount;
        if (factorCount > limit) {
          return power;
        }
      }
    }

    return factorCount;
  }
}
//=====> 실패: 제한 시간 초과 3개
//min time: 0.08ms
//max time: 9466.09ms

//다음 단계:
//for문을 사용하지 않고 모두 내장배열함수 사용하도록 바꾸기

function solution_step3(number, limit, power) {
  return Array(number)
    .fill(0)
    .map((_, idx) => idx + 1) //[1, number]의 범위를 만든다
    .map(knightNumber => calcKnightPower(knightNumber, limit, power))
    .reduce(
      (totalMaterial, weaponPower) => weaponPower + totalMaterial,
      0
    );

  function calcKnightPower(number, limit, power) {
    if (number <= 2) {
      return number; //2 <= limit <= 100
    }

    let factorCount = 2; //1과 자기자신 미리 카운트

    const flooredHalf = Math.floor(number / 2);
    //범위 [2, floor(knightNumber / 2)]
    for (let divider = 2; divider <= flooredHalf; ++divider) {
      if (number % divider === 0) {
        ++factorCount;
        if (factorCount > limit) {
          return power;
        }
      }
    }

    return factorCount;
  }
}
//=====> 실패: 제한 시간 초과 3개
//min time: 0.09ms
//max time: 9832.38ms

//다음 단계:
//약수 개수를 구하는 부분 최적화해보기
function solution_step4(number, limit, power) {
  return Array(number)
    .fill(0)
    .map((_, idx) => idx + 1) //[1, number]의 범위를 만든다
    .map(knightNumber => calcKnightPower(knightNumber, limit, power))
    .reduce(
      (totalMaterial, weaponPower) => weaponPower + totalMaterial,
      0
    );

  function calcKnightPower(number, limit, power) {
    if (number <= 2) {
      return number; //2 <= limit <= 100
    }

    let factorCount = 2; //1과 자기자신 미리 카운트

    //최적화 한 부분 number의 절반이 아니라 number의 제곱근을 사용
    /////////////////////////////////////////////////
    const sqrt = Math.sqrt(number);
    for (let divider = 2; divider <= sqrt; ++divider) {
      /////////////////////////////////////////////////
      if (number % divider === 0) {
        if (divider === number / divider) {
          ++factorCount;
        } else {
          factorCount += 2;
        }
        if (factorCount > limit) {
          return power;
        }
      }
    }

    return factorCount;
  }
}
//=====> 성공
//min time: 0.09ms
//max time: 138.88ms

/* 문제: 기사단원의 무기
숫자나라 기사단의 각 기사에게는 1번부터 number까지 번호가 지정되어 있습니다. 기사들은 무기점에서 무기를 구매하려고 합니다.

각 기사는 자신의 기사 번호의 약수 개수에 해당하는 공격력을 가진 무기를 구매하려 합니다. 
  단, 이웃나라와의 협약에 의해 공격력의 제한수치를 정하고, 
  제한수치보다 큰 공격력을 가진 무기를 구매해야 하는 기사는 
  협약기관에서 정한 공격력을 가지는 무기를 구매해야 합니다.

예를 들어, 15번으로 지정된 기사단원은 
  15의 약수가 1, 3, 5, 15로 4개 이므로, 공격력이 4인 무기를 구매합니다.
  만약, 이웃나라와의 협약으로 정해진 
    공격력의 제한수치가 3이고 
    제한수치를 초과한 기사가 사용할 무기의 공격력이 2라면, 
  15번으로 지정된 기사단원은 무기점에서 공격력이 2인 무기를 구매합니다.
  
무기를 만들 때, 무기의 공격력 1당 1kg의 철이 필요합니다. 그래서 무기점에서 무기를 모두 만들기 위해 필요한 철의 무게를 미리 계산하려 합니다.

기사단원의 수를 나타내는 정수 number와 
이웃나라와 협약으로 정해진 공격력의 제한수치를 나타내는 정수 limit와
제한수치를 초과한 기사가 사용할 무기의 공격력을 나타내는 정수 power가
주어졌을 때, 무기점의 주인이 무기를 모두 만들기 위해 필요한 철의 무게를 return 하는 solution 함수를 완성하시오.

제한사항
  1 ≤ number ≤ 100,000
  2 ≤ limit ≤ 100
  1 ≤ power ≤ limit

https://school.programmers.co.kr/learn/courses/30/lessons/136798
*/
