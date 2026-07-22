
const result = otherSolution('hello WORLD', '_worl', 5);
console.log(result);

function mySolution(my_string, overwrite_string, s) {
	return my_string.slice(0, s) + overwrite_string + my_string.slice(s+overwrite_string.length);
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution(my_string, overwrite_string, s) {
	//Array.prototype.splice 메서드를 사용
	//splice 메서드는 삭제된/교체된 요소들을 배열로 반환한다
	const my_string_array = [...my_string];
	my_string_array.splice(s, overwrite_string.length,overwrite_string);
	return my_string_array.join('');
}