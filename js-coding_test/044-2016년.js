const daysOnMonth = [
   //1월 2월 3월 4월
   31, 29, 31, 30,
   //5월 6월 7월 8월
   31, 30, 31, 31,
   //9월 10월 11월 12월
   30, 31, 30, 31,
];

const remainderToDayNameMap = [
   /* a % 7 = 0 => */ 'FRI',
   /* a % 7 = 1 => */ 'SAT',
   /* a % 7 = 2 => */ 'SUN',
   /* a % 7 = 3 => */ 'MON',
   /* a % 7 = 4 => */ 'TUE',
   /* a % 7 = 5 => */ 'WED',
   /* a % 7 = 6 => */ 'THU',
];

function mySolution(a, b) {
   //2016년 1월 1일부터
   //2016년 a월 b일까지 경과한 날의 개수
   let passedDays = 0;
   for (let month = 0; month < a - 1; ++month) {
      passedDays += daysOnMonth[month];
   }
   passedDays += b - 1;

   return remainderToDayNameMap[passedDays % 7];
}

/*****************
  다른 분들의 풀이
******************/
function otherSolution1(a, b) {
   //Date 인터페이스를 사용
   const date = new Date(2016, a - 1, b);
   const dayName = date.toString().slice(0, 4).toUpperCase();
   return dayName;
}

function otherSolution() {
   //연속된 부분배열을 표현하기 위해 slice를 사용
   const passedDaySum = daysOnMonth
      .slice(0, a - 1)
      .reduce((prev, cur) => prev + cur, b - 1);

   return remainderToDayNameMap[passedDaySum % 7];
}

/* 문제: 2016년
2016년 1월 1일은 금요일입니다. 2016년 a월 b일은 무슨 요일일까요? 

두 수 a ,b를 입력받아 2016년 a월 b일이 무슨 요일인지 리턴하는 함수, solution을 완성하세요. 
요일의 이름은 일요일부터 토요일까지 각각 SUN,MON,TUE,WED,THU,FRI,SAT 입니다. 
예를 들어 a=5, b=24라면 5월 24일은 화요일이므로 문자열 "TUE"를 반환하세요.

제한 조건
  2016년은 윤년입니다.
  2016년 a월 b일은 실제로 있는 날입니다. 
  (13월 26일이나 2월 45일같은 날짜는 주어지지 않습니다)

https://school.programmers.co.kr/learn/courses/30/lessons/12901
*/
