const FixedArrayV2 = require('../FixedArray/FixedArrayV2');

class Queue extends FixedArrayV2 {
  constructor(length) {
    super(length);
  }

  // 큐에 요소를 추가
  enqueue(element) {
    if (this.getLength() >= super.getCapacity()) {
      throw new Error(
        `Queue가 꽉 찼습니다. 큐 용량:${super.getCapacity()} 현재 요소 개수:${this.getLength()}`
      );
    }
    this.push(element);
  }

  // 큐에서 요소를 제거
  dequeue() {
    if (this.isEmpty()) {
      throw new Error(
        `Queue가 비었습니다. 현재 요소 개수:${this.getLength()}`
      );
    }

    const result = this.at(0);

    for (let i = 0; i < this.getLength() - 1; ++i) {
      this.writeAt(i, this.at(i + 1));
    }

    this.writeAt(this.getLength() - 1, undefined);
    this.setLength(this.getLength() - 1);
    return result;
  }

  // 큐의 첫 번째 요소를 확인
  front() {
    if (this.isEmpty()) {
      throw new Error(
        `Queue가 비었습니다. 현재 요소 개수:${this.getLength()}`
      );
    }

    return this.at(0);
  }

  // 큐가 비어있는지 확인
  isEmpty() {
    return this.getLength() === 0;
  }

  // 큐의 요소 수를 확인
  size() {
    return this.getLength();
  }

  // 큐를 비움
  clear() {
    for (let i = 0; i < this.getLength(); ++i) {
      this.writeAt(i, undefined);
    }
    this.setLength(0);
  }

  // 큐의 모든 요소를 출력
  print() {
    console.log(this.stringify());
  }
}

// 사용 예시
const queue = new Queue(10);
queue.enqueue(1);
queue.enqueue(2);
queue.enqueue(3);
queue.print(); // 1,2,3
console.log(queue.dequeue()); // 1
console.log(queue.front()); // 2
queue.print(); // 2,3
