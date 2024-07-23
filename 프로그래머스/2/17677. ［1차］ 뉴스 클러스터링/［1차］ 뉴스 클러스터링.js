function solution(str1, str2) {
    var answer = 1;
    const regex = /^[A-Z]+$/;
    let arr1 =[];
    let arr2 =[];
    let num = 65536;
    for(let i =0;i<str1.length-1;i++){
        let str = str1.slice(i,i+2).toUpperCase();
        if(regex.test(str)) arr1.push(str);
    };
    for(let i =0;i<str2.length-1;i++){
        let str = str2.slice(i,i+2).toUpperCase();
        if(regex.test(str)) arr2.push(str);
    };
    let union = arr1.length;
    let intersection = 0;
    arr2.map((word)=>{
       if(arr1.includes(word)){
           let index = arr1.findIndex((e)=>e===word);
           arr1.splice(index,1);
            intersection++;
       }
        else union++;
    });
    if(arr1.length ===0 && arr2.length===0) return answer * num;
    
    answer = intersection/union;
    return Math.floor(answer * num);
}