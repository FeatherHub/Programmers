const FixedArrayV2 = require('../FixedArray/FixedArrayV2');

class Stack extends FixedArrayV2 {
  constructor(length) {
    super(length);
  }

  // 요소를 스택에 추가
  push(element) {
    super.push(element);
  }

  // 스택에서 요소를 제거
  pop() {
    return super.pop();
  }

  // 스택의 최상단 요소를 확인
  peek() {
    return this.at(this.getLength() - 1);
  }

  // 스택이 비어있는지 확인
  isEmpty() {
    return this.getLength() === 0;
  }

  // 스택의 요소 수를 확인
  size() {
    return this.getLength();
  }

  // 스택을 비움
  clear() {
    while (!this.isEmpty()) {
      this.pop();
    }
  }

  // 스택의 모든 요소를 출력
  print() {
    console.log(this.stringify());
  }
}

// 사용 예시
const stack = new Stack(10);
stack.push(1);
stack.push(2);
stack.push(3);
stack.print(); // 1,2,3
console.log(stack.pop()); // 3
console.log(stack.peek()); // 2
stack.print(); // 1,2
