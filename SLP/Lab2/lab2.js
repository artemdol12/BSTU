function basicOperation(operation, value1, value2){
    if(operation == "+"){
        return value1 + value2;
    }
    if(operation == "-"){
        return value1 - value2;
    }
    if(operation == "*"){
        return value1 * value2;
    }
    if(operation == "/"){
        return value1 / value2;
    }
}
alert(basicOperation('+', 4, 5));
alert(basicOperation('-', 9, 5));
alert(basicOperation('*', 4, 5));
alert(basicOperation('/', 25, 5));

function cube(n) {
    let sum = 0;
    for (let i = 1; i <= n; i++) {
        sum += i * i * i;
    }
    return sum;
}
alert(cube(5));

function sumOfArrElements(arr) {
    let sum1 = 0;
    for (let i1 = 0; i1 < arr.length; i1++) {
        sum1 += arr[i1];
    }
    return sum1 / arr.length;
}
alert(sumOfArrElements([1, 2, 3, 4, 5]));

function reverseEnglishSymbols(str1){
    let finishStr = "";
    for(let j = str1.length; j >= 0; j--){
        if(str1[j] > "A" && str1[j] < "z"){
            finishStr += str1[j];
        }
    }
    return finishStr;
}
alert(reverseEnglishSymbols("JavaScript"));
alert(reverseEnglishSymbols("JavaScr53э? ipt"));

function stringNumbers(n1, s1){
    let result1 = "";
    for(let j1 = 0; j1 < n1; j1++){
        result1 += s1;
    }
    return result1;
}
alert(stringNumbers(3, "Hello"));

function differentStrings(arr1, arr2) {
    let arr2Elements = {};
    for (let i = 0; i < arr2.length; i++) {
        arr2Elements[arr2[i]] = true;
    }
    let result = [];
    for (let i = 0; i < arr1.length; i++) {
        if (!arr2Elements[arr1[i]]) {
            result.push(arr1[i]);
        }
    }

    return result;
}
alert(differentStrings(["мама", "папа", "брат", "дом"], ["мама", "папа"]));