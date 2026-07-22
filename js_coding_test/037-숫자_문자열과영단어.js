const result = solution('12zeroonetwo12');
console.log(result);

function solution(s) {
  const wordToNumberMap = new Map([
    ['zero', '0'],
    ['one', '1'],
    ['two', '2'],
    ['three', '3'],
    ['four', '4'],
    ['five', '5'],
    ['six', '6'],
    ['seven', '7'],
    ['eight', '8'],
    ['nine', '9'],
  ]);

  //'onetwo230' => ['one', 'two', '2', '3', '0']
  const wordAndNumberTokens = tokenizeByWords(s, [
    ...wordToNumberMap.keys(),
  ]);

  //['one', 'two', '2', '3', '0'] => ['1', '2', '2', '3', '0']
  const numberTokens = wordAndNumberTokens.map(token =>
    canConvertToNum(token) ? token : wordToNumberMap.get(token)
  );

  return Number(numberTokens.join(''));

  function tokenizeByWords(s, words) {
    const tokens = [];

    let curPos = 0;
    while (curPos < s.length) {
      const curChar = s[curPos];
      if (canConvertToNum(curChar)) {
        tokens.push(curChar);
        ++curPos;
      } else {
        for (const word of words) {
          let fullMatch = true;

          for (let i = 0; i < word.length; ++i) {
            if (s[curPos + i] !== word[i]) {
              fullMatch = false;
              break;
            }
          }

          if (fullMatch) {
            tokens.push(word);
            curPos += word.length;
            break;
          }
        }
      }
    }

    return tokens;
  }

  function canConvertToNum(character) {
    return !Number.isNaN(Number(character));
  }
}

/* 숫자 문자열과 영단어

네오와 프로도가 숫자놀이를 하고 있습니다. 
네오가 프로도에게 숫자를 건넬 때 
일부 자릿수를 영단어로 바꾼 카드를 건네주면 
프로도는 원래 숫자를 찾는 게임입니다.

다음은 숫자의 일부 자릿수를 영단어로 바꾸는 예시입니다.

1478 → "one4seveneight"
234567 → "23four5six7"
10203 → "1zerotwozero3"

이렇게 숫자의 일부 자릿수가 영단어로 바뀌어졌거나, 
혹은 바뀌지 않고 그대로인 
문자열 s가 매개변수로 주어집니다. 
s가 의미하는 원래 숫자를 return 하도록 solution 함수를 완성해주세요.

https://school.programmers.co.kr/learn/courses/30/lessons/81301
*/
