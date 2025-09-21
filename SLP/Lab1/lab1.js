let a = 5;
let name = "Name";
let i = 0;
let double = 0.23;
let result = 1/0;
let answer = true;
let no = null;

console.log(typeof(a));
console.log(typeof(name));
console.log(typeof(i));
console.log(typeof(double));
console.log(typeof(result));
console.log(typeof(answer));
console.log(typeof(no));

let Sb = 5 * 5;
let Sa = 45 * 21;
let Result = Sa / Sb;
let roundedResult = Math.floor(Result);
console.log(`Количество квадратов к-ые можно разместить: ${roundedResult}`);


let i1 = 2;
let a1 = ++i1;
let b1 = i1++;
if(a1>b1){
    console.log(`Первое значение больше второго`);    
}
else if(a1 < b1){
    console.log('Первое значение меньше, чем второе');
}
else{
    console.log('Значения равны между собой');
}

let result1 = "Котик" === "котик" ? "равны" : "не равны";
console.log(result1);
let result2 = "Котик" === "китик" ? "равны" : "не равны";
console.log(result2);
let result3 = "Кот" === "Котик" ? "равны" : "не равны";
console.log(result3);
let result4 = "Привет" === "Пока" ? "равны" : "не равны";
console.log(result4);
let result5 = 73 == "53" ? "равны" : "не равны";
console.log(result5);
let result6 = false == 0 ? "равны" : "не равны";
console.log(result6);
let result7 = 54 == true ? "равны" : "не равны";
console.log(result7);
let result8 = 123 == false ? "равны" : "не равны";
console.log(result8);
let result9 = true == "3" ? "равны" : "не равны";
console.log(result9);
let result10 = 3 == "5мм" ? "равны" : "не равны";
console.log(result10);
let result11 = 8 == "-2" ? "равны" : "не равны";
console.log(result11);
let result12 = 34 == "34" ? "равны" : "не равны";
console.log(result12);
let result13 = null == undefined ? "равны" : "не равны";
console.log(result13);

let correctName = false;

do {
    let userInput = prompt("Введите имя преподавателя:");
    
    if (userInput) {
        if (userInput === "Марина" || userInput === "Марина Фёдоровна" || userInput === "Кудлацкая Марина Фёдоровна") {
            alert("Введенные данные верные!");
            correctName = true;
        } else {
            alert("Введенные данные неверные! Попробуйте еще раз.");
        }
    } else {
        alert("Пожалуйста, введите имя преподавателя.");
    }
} while (!correctName);

let russian;
let math;
let english;
russian = prompt("Введите оценку по русскому языку: ");
math = prompt("Введите оценку по математике: ");
english = prompt("Введите оценку по английскому языку: ");
if(russian > 4 && math > 4 && english > 4){
    alert("Студент переведён на следующий год");
}
else if(russian < 4 && math < 4 && english < 4){
    alert("Студент отчислен из университета");
}
else if(russian < 4 || math < 4 || english < 4){
    alert("Студента ожидает пересдача");
}

console.log(true + true);
console.log(0 + "5");
console.log(5 + "мм");
console.log(8/Infinity);
console.log(9 * "\n9");
console.log(null - 1);
console.log("5" - 2);
console.log("5px" - 3);
console.log(true - 3);
console.log(7 || 0);

let userNumber = parseInt(prompt("Введите число от 1 до 10: "));
if (userNumber >= 1 && userNumber <= 10) {
    if (userNumber % 2 == 0) {
        alert(userNumber + 2);
    } else {
        alert(userNumber + "мм");
    }
} else {
    alert("Число вне диапазона от 1 до 10");
}

let daysOfWeek = {
    1: "Понедельник",
    2: "Вторник",
    3: "Среда",
    4: "Четверг",
    5: "Пятница",
    6: "Суббота",
    7: "Воскресенье"
};
let dayNumber = parseInt(prompt("Введите номер дня недели (1-7): "), 10);
if (dayNumber >= 1 && dayNumber <= 7) {
    alert("Это " + daysOfWeek[dayNumber]);
} else {
    alert("Неверный номер дня недели");
}

let DaysOfWeek = ["Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"];
let DayNumber = parseInt(prompt("Введите номер дня недели (1-7): "), 10);
if (DayNumber >= 1 && DayNumber <= 7) {
    alert("Это " + DaysOfWeek[DayNumber - 1]);
} else {
    alert("Неверный номер дня недели");
}

function fisrtFunction(str1 = "первый параметр", str2, str3 = prompt("Введите третий параметр: ")){
    return str1 + " " + str2 + " " + str3;
}
alert(fisrtFunction());

let a11 = parseFloat(prompt("Введите первую сторону: "));
let b11 = parseFloat(prompt("Введите вторую сторону: "));
function params(a11, b11) {
    if (a11 == b11) {
        return a11 * 4;
    } else {
        return a11 * b11;
    }
}
alert(params(a11, b11));

let a12 = parseFloat(prompt("Введите первую сторону: "));
let b12 = parseFloat(prompt("Введите вторую сторону: "));
let params1 = function(a12, b12) {
    if (a12 == b12) {
        return a12 * 4;
    } else {
        return a12 * b12;
    }
}
alert(params1(a12, b12));

let a13 = parseFloat(prompt("Введите первую сторону: "));
let b13 = parseFloat(prompt("Введите вторую сторону: "));
let params2 = (a13, b13) => {
    if (a13 == b13) {
        return a13 * 4;
    } else {
        return a13 * b13;
    }
}
alert(params2(a13, b13));