function mySolution(number, n, m) {
	const divisible = (dividend, divider) => dividend % divider === 0;

	const testCommonMultiple = (number, divider1, divider2) =>
		divisible(number, divider1) && divisible(number, divider2);

	return testCommonMultiple(number, n, m) ? 1 : 0;
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution(number, n, m) {
	//1. 암묵적 형변환을 적극적으로 사용
	//2. 둘 다 divisible해야 결과가 true라는 사실이 아니라  
	//둘 중 하나라도 divisible하지 않으면 결과가 false라는 사실에 중점

	return +!(number % n || number % m ); 
}