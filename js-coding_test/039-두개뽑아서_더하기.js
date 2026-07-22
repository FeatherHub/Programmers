const result = solution([1,2,3]);
console.log(result);

function solution(numbers) {
	const allIndexPairs = getAllPairFromRange(0, numbers.length);
	const allAddedValues = allIndexPairs.map(addByIndex);
	const dupRemoved = removeDuplicate(allAddedValues);
	const sorted = dupRemoved.sort((a, b) => a - b);

	return sorted;

	function getAllPairFromRange(fromInclusive, toExclusive) {
		const resultArr = [];
		for (let i = fromInclusive; i < toExclusive; ++i) {
			for(let j = i + 1; j < toExclusive; ++j) {
				resultArr.push([i, j]);
			}
		}

		return resultArr;
	}

	function addByIndex([index1, index2]) {
		return numbers[index1] + numbers[index2];
	}

	function removeDuplicate(array) {
		return [...new Set(array)];
	}
}


/* 문제: 두 개 뽑아서 더하기
정수 배열 numbers가 주어집니다. 
numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 
더해서 만들 수 있는 모든 수를
배열에 오름차순으로 담아 
return 하도록 solution 함수를 완성해주세요.

https://school.programmers.co.kr/learn/courses/30/lessons/68644
*/

/* 나의 풀이
numbers에서 
서로 다른 인덱스에 있는 두 개의 수를 뽑아
  서로 다른 인덱스 => i, j
  i != j
  (i, j)를 뽑는 것은 
  (j, i)을 뽑는 것과 같음 => 조합 구하기
  이중 루프 i = [0, len),  j = [i+1, len)를 사용해서
  모든 조합을 표현하기
더해서 만들 수 있는 모든 수를
  중복되는 수를 제거하기 위해 Set 생성자 함수 이용
배열에 오름차순으로 담아
  배열의 sort 메서드 사용
  수 비교이므로 비교 함수 지정하기
*/

