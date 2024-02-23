 const deletSideDot=(str)=>{
        let split = str.split('');
        if(split[0]==='.') split.splice(0,1);
        if(split[split.length-1]==='.') split.splice(split.length-1,1);
        return split.join('');
    }
 
 const deleteDot=(str)=>{
    let split_id = str.split('');
    let temp = '';
    for(let i =0;i<split_id.length;i++){//3단계
        if(split_id[i]==='.'){
            if(split_id[i+1]!=='.'){
                temp+=split_id[i];
            }
        }else{
            temp+=split_id[i];
        }
    }
     return temp
 }
 const sliceNew_id=(str)=>{
     if(str.length>=16) str = str.slice(0,15);//6단계
    str= deletSideDot(str);
     return str
 }
function solution(new_id) {
    var answer = '';
    new_id=new_id.toLowerCase();// 1단계
    new_id=new_id.replace(/[^\w-._]+/g,'');//2단계
    new_id = deleteDot(new_id);//3단계
    new_id = deletSideDot(new_id);//4단계
    if(new_id ==='') new_id='a'; //5단계
    new_id = sliceNew_id(new_id);//6단계
    while(new_id.length<=2){//7단계
        new_id+=new_id[new_id.length-1];
    }
    answer = new_id;
    return answer;
}
//뉴아이디가 닷이고 이전에 저장한 것도 닷이면 삭제
//뉴아이디가 닷이고 이전에 저장한게 닷이 아니면 삭제 x 이전에 저장 