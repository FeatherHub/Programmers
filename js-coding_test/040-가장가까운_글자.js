const result = otherSolution("foobar");
console.log(result);

function solution(s) {
	const resultArray = [];

	for (let i = 0; i < s.length; ++i) {
		let nearestDistance = -1;

		for (let j = i - 1; j >= 0; --j) {
			if (s[i] === s[j]) {
				nearestDistance = i - j;
				break;
			}
		}

		resultArray.push(nearestDistance);
	}

	return resultArray;
}

/* 나의 풀이
문자열 s가 주어졌을 때, s의 각 위치마다 
  => i = [0, s.length)의 범위를 스캔한다.

자신보다 앞에 나왔으면서,  
자신과 가장 가까운 곳에 있는 
같은 글자
  => 서브 루프 j = [i-1, 0]의 범위를 거꾸로 스캔한다.
	  s[i] === s[j]인 j가 발견되면 
		 i-j를 결과 배열에 푸시하고 서브 루프를 종료한다.
	  발견되지 않으면 
		 결과 배열에 -1을 푸시한다. 
*/

/*****************
  다른 분들의 풀이
******************/
function otherSolution(s) {
	//소스 길이와 결과 길이가 같다는 것에 착안해서 
	//Array의 map 메서드를 사용한다
	//map 콜백함수에서 
	//  Array의 slice 메서드를 사용해 [0, i)의 부분 배열을 표현한다.
	//  Array의 lastIndexOf 메서드를 사용해 현재 원소와 가장 가까운, 같은 값을 가진 원소의 인덱스를 구한다.
	return [...s].map((targetChar, targetIndex) => {
		const nearestIndex = s.slice(0, targetIndex).lastIndexOf(targetChar);

		return nearestIndex < 0 ? -1 : targetIndex - nearestIndex;
	});
}

/* 문제: 가장 가까운 글자
문자열 s가 주어졌을 때, 
  s의 각 위치마다 
	 자신보다 앞에 나왔으면서, 자신과 가장 가까운 곳에 있는 
	 같은 글자가 어디 있는지 알고 싶습니다.

예를 들어, s="banana"라고 할 때,  
각 글자들을 왼쪽부터 오른쪽으로 읽어 나가면서 
다음과 같이 진행할 수 있습니다.

b는 처음 나왔기 때문에 자신의 앞에 같은 글자가 없습니다. 이는 -1로 표현합니다.
a는 처음 나왔기 때문에 자신의 앞에 같은 글자가 없습니다. 이는 -1로 표현합니다.
n은 처음 나왔기 때문에 자신의 앞에 같은 글자가 없습니다. 이는 -1로 표현합니다.
a는 자신보다 두 칸 앞에 a가 있습니다. 이는 2로 표현합니다.
n도 자신보다 두 칸 앞에 n이 있습니다. 이는 2로 표현합니다.
a는 자신보다 두 칸, 네 칸 앞에 a가 있습니다. 이 중 가까운 것은 두 칸 앞이고, 이는 2로 표현합니다.

따라서 최종 결과물은 [-1, -1, -1, 2, 2, 2]가 됩니다.

문자열 s이 주어질 때, 위와 같이 정의된 연산을 수행하는 함수 solution을 완성해주세요.

https://school.programmers.co.kr/learn/courses/30/lessons/142086
*/