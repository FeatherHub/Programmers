function mySolution(arr, queries) {
	queries.forEach(([i, j]) => {
		const tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	});

	return arr;
}

/* pseudo-code
  queries를 순회하며 swap을 arr에 적용한다
  수정된 arr을 반환한다
*/

/*****************
  다른 분들의 풀이
******************/
function otherSolution(arr, queries) {
	//배열디스트럭처링 응용
	queries.forEach(([i, j]) => {
		[arr[i], arr[j]] = [arr[j], arr[i]];
	})

	return arr;
}

function otherSolution2(arr, queries) {
	//원본 배열을 수정하지 않는 방식
	return queries.reduce((shuffle, [i, j]) => {
		[shuffle[i], shuffle[j]] = [shuffle[j], shuffle[i]];
		return shuffle;
	}, [...arr]);
}

/* 문제: 수열과 구간 쿼리 3
정수 배열 arr와 2차원 정수 배열 queries이 주어집니다. 
queries의 원소는 각각 하나의 query를 나타내며, [i, j] 꼴입니다.

각 query마다 순서대로 arr[i]의 값과 arr[j]의 값을 서로 바꿉니다.

위 규칙에 따라 queries를 처리한 이후의 arr를 return 하는 solution 함수를 완성해 주세요.
*/