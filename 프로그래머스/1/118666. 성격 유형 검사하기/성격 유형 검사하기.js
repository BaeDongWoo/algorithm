function solution(survey, choices) {
    let answer = "RCJA";
    let category =['R','T','C','F','J','M','A','N'];
    let map = new Map();
    for (let i =0;i<category.length;i++){
        map.set(category[i],0);
    };
   
    for (let i =0;i<survey.length;i++){
        const first = survey[i][0];
        const second = survey[i][1];
        const score = Math.abs(choices[i]-4);
        if(choices[i]<4) map.set(first,map.get(first)+score);
        else if(choices[i]>4) map.set(second,map.get(second)+score);
    };
    console.log(map);
    if(map.get('R')<map.get('T')) answer = answer.replace("R","T");
    if(map.get('C')<map.get('F')) answer = answer.replace("C","F");
    if(map.get('J')<map.get('M')) answer = answer.replace("J","M");
    if(map.get('A')<map.get('N')) answer = answer.replace("A","N");
   
    return answer;
}
