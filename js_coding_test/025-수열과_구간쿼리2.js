const result = mySolution([0, 1, 2, 4, 3], [[0, 4, 2], [0, 3, 2], [0, 2, 2]]);

console.log(result);

function mySolution(arr, queries) {
	const answer = [];

	queries.forEach(query => {
		const [startIdx, endIdx, threshold] = query;
		const greaterThanThreshold = [];
		for (let i = startIdx; i <= endIdx; ++i) {
			const cur = arr[i];
			if (cur > threshold) {
				greaterThanThreshold.push(cur);
			}
		}

		if (greaterThanThreshold.length) {
			answer.push(Math.min(...greaterThanThreshold));
		} else {
			answer.push(-1);
		}
	}); //forEach-end

	return answer;
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution(arr, queries) {
	//map: slice로 arr에서 [s, e] 범위를 추출한다
	//filter: k 보다 큰 원소를 모은다
	//sort: 가장 작은 원소를 찾는다

	return queries.map(([s, e, k]) => {
		return arr.slice(s, e + 1)
			.filter(v => v > k)
			.sort((a, b) => a - b)[0] ?? -1;
	});
}

/* 문제: 수열과 구간 쿼리 2
정수 배열 arr와 2차원 정수 배열 queries이 주어집니다. 
queries의 원소는 각각 하나의 query를 나타내며, [s, e, k] 꼴입니다.

각 query마다 순서대로 s ≤ i ≤ e인 모든 i에 대해 k보다 크면서 가장 작은 arr[i]를 찾습니다.

각 쿼리의 순서에 맞게 답을 저장한 배열을 반환하는 solution 함수를 완성해 주세요. 단, 특정 쿼리의 답이 존재하지 않으면 -1을 저장합니다.
*/