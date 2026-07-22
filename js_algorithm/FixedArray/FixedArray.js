class FixedArray {
  #array = [];
  #arrayLength = 0;
  #currentLength = 0;

  constructor(length) {
    this.#arrayLength = length;

    for (let i = 0; i < length; ++i) {
      this.#array[i] = undefined;
    }
  }

  push(element) {
    if (this.#currentLength >= this.#arrayLength) {
      throw new Error('배열이 꽉 찼습니다.');
    }

    const insertionPointIdx = this.#currentLength;
    this.#array[insertionPointIdx] = element;

    ++this.#currentLength;
  }

  pop() {
    if (this.#currentLength <= 0) {
      throw new Error('배열이 비었습니다');
    }

    const topElemIdx = this.#currentLength - 1;

    const element = this.#array[topElemIdx];
    this.#array[topElemIdx] = undefined;

    --this.#currentLength;

    return element;
  }

  getLength() {
    return this.#currentLength;
  }

  stringify() {
    let str = '';
    str += '[';
    for (let i = 0; i < this.#currentLength; ++i) {
      str += JSON.stringify(this.#array[i]);
      if (i !== this.#currentLength - 1) {
        str += ', ';
      }
    }
    str += ']';
    return str;
  }

  at(index) {
    return this.#array[index];
  }

  writeAt(index, element) {
    this.#array[index] = element;
  }

  setLength(newLength) {
    this.#currentLength = newLength;
  }

  getCapacity() {
    return this.#arrayLength;
  }
}

module.exports = FixedArray;
