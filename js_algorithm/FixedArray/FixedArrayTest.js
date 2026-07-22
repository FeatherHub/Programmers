const FixedArray = require('./FixedArray');

const ARRAY_LENGTH = 10;
const fixedArray = new FixedArray(ARRAY_LENGTH);

fixedArray.push(10);
fixedArray.push(20);
fixedArray.push(30);
fixedArray.push(40);

console.log(fixedArray.getLength());
console.log(fixedArray.stringify());

console.log(fixedArray.pop());
console.log(fixedArray.pop());
console.log(fixedArray.pop());
console.log(fixedArray.pop());
try {
   console.log(fixedArray.pop());
} catch (error) {
   console.log(error.message);
}

for (let i = 0; i < ARRAY_LENGTH; ++i) {
   fixedArray.push(999);
}
try {
   fixedArray.push(1000);
} catch (error) {
   console.log(error.message);
}
