function solution(phone_book) {
    var answer = true;
    phone_book.sort();
    for(let i =0;i<phone_book.length-1;i++){
        const prefixSize = phone_book[i].length;
        const prefix = phone_book[i+1].slice(0,prefixSize);
        if(phone_book[i]===prefix) return false;
    }
    return answer;
}