"use strict"
const reader = require('readline').createInterface({
    input: require('fs').createReadStream('a2_input.txt')
});

const regex = new RegExp(/^\$\**([1-9]\d{0,2}(,\d{3})*|0).\d\d$/);
console.log("Starting JavaScript Program Type to Check RegEx\n")

reader.on('line', (line) => {
    if(regex.test(line)){
        console.log(line + " is a valid money format.");
    }
    else{
        console.log(line + " is an invalid money format.");
    }
});
