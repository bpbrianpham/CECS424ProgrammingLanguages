'use strict'

let convertFloat = (val) => {
    // Byte buffer
    let buffer = new ArrayBuffer(4);
    // Fill the byte buffer with the floating point value
    let floatBuffer = new Float32Array(buffer);
    floatBuffer.fill(val);
    // Retrieve the unsigned interger representation of those values
    let uint = new Uint32Array(buffer);

    // Shift and return
    return [
        (uint & 0x80000000) >>> 31, 
        (uint & 0x7f800000) >>> 23, 
        (uint & 0x007fffff)
    ]
};

let nextFloat = (val) => {
    // Byte buffer
    let buffer = new ArrayBuffer(4);
    // Fill the byte buffer with the floating point value
    let floatBuffer = new Float32Array(buffer);
    floatBuffer.fill(val);
    let intBuffer = new Uint32Array(buffer);
    intBuffer.fill(intBuffer[0] + 1);

    return floatBuffer;
};

let countBetween = (start, end) =>{
    // Byte buffer
    let buffer = new ArrayBuffer(4);
    // Fill the byte buffer with the floating point value
    let floatBuffer = new Float32Array(buffer);
    floatBuffer.fill(start);
    let intBuffer = new Uint32Array(buffer);
    
    // Retrieve the unsigned int value for the start
    let startUint = intBuffer[0];

    // Retrieve the unsigned int value for the end
    floatBuffer.fill(end);
    let endUint = intBuffer[0];

    return endUint - startUint;

}

console.log('i. Floating point number converter.');
let pi =  3.14159265358979;
console.log(`${pi} -> (${convertFloat(pi)})\n`);

console.log('ii. Floating point number enumeration.');
let fp = 0.0;
let i = 0;

while(fp < 1.4E-44) {
    fp = nextFloat(fp);
    console.log(`${++i}th number: << ${fp}`);
}

console.log('iii. Floating point number counting');
let posFPs = countBetween(0.0, 3.4028235E38);
let zeroOneFPs = countBetween(0.0, 1.0);
console.log(`Number of positive floating point numbers: ${posFPs}`);
console.log(`Number of floating point numbers between 0 and 1: ${zeroOneFPs}`);
console.log(`Proportion (# of 0~1) / (# of positive): ${(zeroOneFPs / posFPs) * 100}`);