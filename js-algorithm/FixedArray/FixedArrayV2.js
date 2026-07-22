const FixedArray = require('./FixedArray');

class FixedArrayV2 extends FixedArray {
   constructor(length) {
      super(length);
   }

   indexOf(searchElement) {
      const length = this.getLength();
      for (let i = 0; i < length; ++i) {
         if (this.at(i) === searchElement) {
            return i;
         }
      }
      return -1;
   }

   find(predicate) {
      let result = null;

      const length = this.getLength();
      for (let i = 0; i < length; ++i) {
         const element = this.at(i);
         if (predicate(element)) {
            result = element;
            break;
         }
      }

      return result;
   }

   findIndex(predicate) {
      for (let i = 0; i < this.getLength(); ++i) {
         if (predicate(this.at(i))) {
            return i;
         }
      }
      return -1;
   }

   includes(searchElement) {
      const result = this.findIndex(
         element => element === searchElement
      );
      return result === -1 ? false : true;
   }

   includesV2(searchElement) {
      for (let i = 0; i < this.getLength(); ++i) {
         const element = this.at(i);
         if (element === searchElement) {
            return true;
         }
      }
      return false;
   }

   forEach(callback) {
      const length = this.getLength();
      for (let i = 0; i < length; ++i) {
         const element = this.at(i);
         callback(element, i);
      }
   }

   filter(predicate) {
      const filteredArray = [];

      const length = this.getLength();
      for (let i = 0; i < length; ++i) {
         const element = this.at(i);
         if (predicate(element)) {
            filteredArray.push(element);
         }
      }

      return FixedArrayV2.fromJSArray(filteredArray);
   }

   map(callback) {
      const mappedArray = [];

      const length = this.getLength();
      for (let i = 0; i < length; ++i) {
         const element = this.at(i);
         const mappedElement = callback(element, i);
         mappedArray.push(mappedElement);
      }

      return FixedArrayV2.fromJSArray(mappedArray);
   }

   reduce(callback, initValue) {
      let startIndex = 0;

      let accumulator;

      if (initValue !== undefined) {
         accumulator = initValue;
      } else {
         accumulator = this.at(startIndex);
         ++startIndex;
      }

      const length = this.getLength();
      for (let i = startIndex; i < length; ++i) {
         const current = this.at(i);
         accumulator = callback(accumulator, current, i);
      }

      return accumulator;
   }

   static fromJSArray(jsArray) {
      const fixedArrayV2 = new FixedArrayV2(jsArray.length);
      for (let i = 0; i < jsArray.length; ++i) {
         fixedArrayV2.push(jsArray[i]);
      }
      return fixedArrayV2;
   }
}

module.exports = FixedArrayV2;