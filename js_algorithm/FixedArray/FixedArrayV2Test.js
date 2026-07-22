const FixedArrayV2 = require('./FixedArrayV2');

const fixedArrayV2 = new FixedArrayV2(10);

for (let i = 1; i <= 10; ++i) {
   fixedArrayV2.push(10 * i);
}

console.log('[[findIndex test]]');
console.log(fixedArrayV2.findIndex(elem => elem > 10));

console.log('[[indexOf test]]');
console.log(fixedArrayV2.indexOf(50));
console.log(fixedArrayV2.indexOf(-1));

console.log('[[includes test]]');
console.log(fixedArrayV2.includes(10));
console.log(fixedArrayV2.includes(-1));

console.log('[[includesV2 test]]');
console.log(fixedArrayV2.includesV2(10));
console.log(fixedArrayV2.includesV2(-1));

console.log('[[at test]]');
for (let i = -2; i < 3; ++i) {
   console.log(fixedArrayV2.at(i));
}

console.log('[[forEach test]]');
fixedArrayV2.forEach((elem, i) =>
   console.log(`elem ${i} => ${elem}`)
);

console.log('[[filter test]]');
console.log(fixedArrayV2.filter(elem => elem % 3 === 0).stringify());

console.log('[[reduce test]]');
console.log(fixedArrayV2.reduce((prev, cur) => prev + cur));
console.log(fixedArrayV2.reduce((prev, cur) => prev + cur, 250));
