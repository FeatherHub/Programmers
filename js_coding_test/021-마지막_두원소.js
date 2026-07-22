const result = mySolution([1,2,3,4,5]);
console.log(result);

function mySolution(num_list) {
	const [secondLastNum, lastNum] = num_list.slice(-2);
	
	let numToPush = lastNum > secondLastNum ?
		lastNum - secondLastNum :
		lastNum * 2;
	
	//매개변수로 전달된 배열이 수정된다.
	num_list.push(numToPush);

	return num_list;
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution(num_list) {
	//reverse 메서드 활용
	//reverse 메서드는 메서드를 호출한 배열을 수정한다.
	const [firstNum, secondNum] = [...num_list].reverse();

	let numToInsert = firstNum > secondNum ?
		firstNum - secondNum :
		firstNum * 2;

	return [...num_list, numToInsert];
}

/* 문제
정수 리스트 num_list가 주어질 때, 
  마지막 원소가 그전 원소보다 크면 
    마지막 원소에서 그전 원소를 뺀 값을 
  마지막 원소가 그전 원소보다 크지 않다면 
    마지막 원소를 두 배한 값을 
  추가하여 
return하도록 solution 함수를 완성해주세요.
 */
