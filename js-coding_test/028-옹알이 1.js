const result = mySolution(['ayaye', 'wooma']);
console.log(result);

function mySolution(babbling) {
	const tokens = ['aya', 'ye', 'woo', 'ma'];

	const words = permutation(tokens);

	const talkableBabbles = babbling.filter(babble => 
		words.find(word => babble === word) ?? false
	);
	
	return talkableBabbles.length;

	function permutation(array){
		const resultArray = [];

		_permutation(array, '');
		
		return [...new Set(resultArray)];

		function _permutation(array, prev) {
			if(array.length === 1) {
				resultArray.push(prev+array[0]);
				return;
			}

			for(let i = 0; i < array.length; ++i) {
				const shrinked = array.slice();
				shrinked.splice(i, 1);
				_permutation(shrinked, prev + array[i]);
				_permutation(shrinked, prev);
			}
		}
	}
}

/* 문제: 옹알이 (1)
머쓱이는 태어난 지 6개월 된 조카를 돌보고 있습니다. 
조카는 아직 
  "aya", "ye", "woo", "ma" 네 가지 발음을 
  최대 한 번씩 사용해 조합한(이어 붙인) 발음밖에 하지 못합니다. 
문자열 배열 babbling이 매개변수로 주어질 때, 
머쓱이의 조카가 발음할 수 있는 단어의 개수를 return하도록 solution 함수를 완성해주세요.

https://school.programmers.co.kr/learn/courses/30/lessons/120956
*/
