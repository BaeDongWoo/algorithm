function solution(today, terms, privacies) {
    var answer = [];
    let todayDate= today.split('.').map(Number);
    let termsMap=new Map();
    for(let i =0;i<terms.length;i++){
        let term=terms[i].split(' ');
        termsMap.set(term[0],term[1]);
    }
    for(let i =0;i<privacies.length;i++){
        let p=privacies[i].split(' ');
        let date=p[0].split('.').map(Number);
        let type=p[1];
        let month=termsMap.get(type);
        let tempDate=setPrivacies(date,month);
        
        if(todayDate[0]>tempDate[0]){
            answer.push(i+1);
        }
        else if(todayDate[0]===tempDate[0]){
            if(todayDate[1]>tempDate[1]){
                answer.push(i+1);
            }
            else if (todayDate[1]===tempDate[1]){
                if(todayDate[2]>tempDate[2]){
                    answer.push(i+1);
                }
            }
        }
    }
    return answer;
}
const setPrivacies=(date,month)=>{
    let Date=date;
    Date[2]=Date[2]-1;
    if(Date[2]===0){
        Date[2]=28;
        Date[1]=Date[1]-1;
        if(Date[1]===0){
            Date[1]=12;
            Date[0]=Date[0]-1;
        }
    }
    Date[1]+=Number(month);
    if(Date[1]>12){   
        if(Date[1] % 12 === 0){
                Date[0] += parseInt(Date[1]/12) - 1; 
                Date[1] = 12;
            }else{
                Date[0] += parseInt(Date[1]/12);
                Date[1] = Date[1] % 12;
            }
    }
    return Date;
}