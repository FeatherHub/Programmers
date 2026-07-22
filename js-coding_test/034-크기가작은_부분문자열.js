const result = solution("1230993", "777");
console.log(result);

function solution(t, p) {
	const subarraysOfSizeP = subarray([...t], p.length);
	const numbersOfLenP = subarraysOfSizeP.map(subarray =>
		Number(subarray.join(''))
	);

	const compareNumber = Number(p);
	const lessThanEqualCount = numbersOfLenP.reduce((lteCnt, number) => {
		return number <= compareNumber ? lteCnt + 1 : lteCnt;
	}, 0);

	return lessThanEqualCount;

	function subarray(array, size) {
		const subarrays = [];
		const lastSubArrayIdx = array.length - size;
		for (let i = 0; i <= lastSubArrayIdx; ++i) {
			subarrays.push([]);
			for (let j = 0; j < size; ++j) {
				subarrays[i].push(array[i + j]);
			}
		}
		return subarrays;
	}
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution(t, p) {
	//substring 메서드를 활용
	//one-pass에 표현

	let lessThanEqualCount = 0;
	const compareNumber = Number(p);
	const indexOfLastSubStr = t.length - p.length;
	for (let i = 0; i <= indexOfLastSubStr; ++i) {
		const substrNumber = Number(t.substring(i, i+p.length));
		if(substrNumber <= compareNumber) {
			++lessThanEqualCount;
		}
	}
	return lessThanEqualCount;
}

/* 문제: 크기가 작은 문자열
숫자로 이루어진 문자열 t와 p가 주어질 때, 
  t에서 
    p와 길이가 같은 부분문자열 중에서, 
  이 부분문자열이 나타내는 수가 
    p가 나타내는 수보다 
    작거나 같은 것이 나오는 
    횟수를 
return하는 함수 solution을 완성하세요.

https://school.programmers.co.kr/learn/courses/30/lessons/147355
*/