/**
 * @param {number} num
 * @return {boolean}
 */

 // babylonian law algorithm
const sqrt = (value) => {
    let x = value / 2;
 
    for(let i = 0; i < 20; ++i) {
        x = (x + ( value / x )) / 2;
    }
    
    return x;
}

var isPerfectSquare = function(num) {
    return Number.isInteger(sqrt(num));
};