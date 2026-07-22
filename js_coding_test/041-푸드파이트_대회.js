const result = otherSolution([1, 3, 4, 6]);

console.log(result);

function solution(food) {
	const resultArray = [];
	for (let i = food.length - 1; i >= 1; --i) {
		const foodNumberPerPlayer = Math.trunc(food[i] / 2);

		//insert ith food foodNumberPerPlayer times
		for (let j = 0; j < foodNumberPerPlayer; ++j) {
			resultArray.unshift(i); //for player starting from left
			resultArray.push(i); //for player starting from right
		}
	}

	//insert 0th food in the middle of the result array
	resultArray.splice(resultArray.length / 2, 0, 0);

	return resultArray.join('');
}


/* 나의 풀이
i = [food.length - 1, 1]인 루프를 스캔하며
i번 음식 개수를 2로 나눈다
  i번 음식이 1개인 경우
	 1 / 2 = 0
	 i를 결과배열 양끝에 0개씩 배치
  i번 음식이 홀수개인 경우
	 3 / 2 = 1
	 i를 결과배열 양끝에 1개씩 배치
  i번 음식이 짝수개인 경우
	 2 / 2 = 1
	 i를 결과배열 양끝에 1개씩 배치

루프 스캔이 완료되면
결과배열 중앙에 0을 삽입한다
  result = [1, 1]
	 result.splice(result.length / 2, 0, 0)
	 2 / 2 = 1
	 => [1, 0, 1]
  result = []
	 result.splice(result.length / 2, 0, 0)
	 0 / 2 = 0
	 => [0]
*/

/*****************
  다른 분들의 풀이
******************/
function otherSolution(food) {
	//결과배열이 가운데 0을 두고 대칭되는 형태를 가진다는 사실을 활용한다.
	//대칭형태 중 0의 왼쪽 부분을 만든다.
	const leftSymmetryPart = [];
	for (let i = 1; i < food.length; ++i) {
		const ithFoodPlacement = String(i).repeat(food[i] / 2);
		leftSymmetryPart.push(ithFoodPlacement);
	}

	const rightSymmetryPart = [...leftSymmetryPart].reverse();

	return [...leftSymmetryPart, 0, ...rightSymmetryPart].join('');
}

/* 문제: 푸드 파이트 대회
https://school.programmers.co.kr/learn/courses/30/lessons/134240

수웅이는 매달 주어진 음식을 빨리 먹는 푸드 파이트 대회를 개최합니다. 
이 대회에서 선수들은 
  1대 1로 대결하며, 
매 대결마다 음식의 종류와 양이 바뀝니다. 

대결은 
  준비된 음식들을 일렬로 배치한 뒤, 
  한 선수는 제일 왼쪽에 있는 음식부터 오른쪽으로, 
  다른 선수는 제일 오른쪽에 있는 음식부터 왼쪽으로 
순서대로 먹는 방식으로 진행됩니다. 
  중앙에는 물을 배치하고, 
물을 먼저 먹는 선수가 승리하게 됩니다.

이때, 대회의 공정성을 위해 
  두 선수가 먹는 음식의 종류와 양이 같아야 하며, 
  음식을 먹는 순서도 같아야 합니다. 
  또한, 이번 대회부터는 칼로리가 낮은 음식을 먼저 먹을 수 있게 배치하여
선수들이 음식을 더 잘 먹을 수 있게 하려고 합니다. 
이번 대회를 위해 수웅이는 음식을 주문했는데, 
대회의 조건을 고려하지 않고 음식을 주문하여 
  몇 개의 음식은 대회에 사용하지 못하게 되었습니다.

예를 들어, 3가지의 음식이 준비되어 있으며, 
칼로리가 적은 순서대로 
  1번 음식을 3개, 
  2번 음식을 4개, 
  3번 음식을 6개 준비했으며, 
  물을 편의상 0번 음식이라고 칭한다면, 
두 선수는 
  1번 음식 1개, 
  2번 음식 2개, 
  3번 음식 3개씩을 
먹게 되므로 
  음식의 배치는 "1223330333221"이 됩니다. 
  따라서 1번 음식 1개는 대회에 사용하지 못합니다.

수웅이가 준비한 음식의 양을 
칼로리가 적은 순서대로 나타내는 정수 배열 food가 주어졌을 때, 
대회를 위한 음식의 배치를 나타내는 
  문자열을 
return 하는 solution 함수를 완성해주세요.
*/