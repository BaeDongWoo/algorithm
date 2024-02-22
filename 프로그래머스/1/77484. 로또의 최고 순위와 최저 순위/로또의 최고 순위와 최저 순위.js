function solution(lottos, win_nums) {
    var answer = [];
    const wins = [6,6,5,4,3,2,1];
    lottos = lottos.filter((e)=> e!==0);
    const zeroNum = 6-lottos.length;
    let minWin = 0;
    let maxWin =zeroNum;
    lottos.map((lotto)=>{
        if(win_nums.find((num)=>num===lotto))minWin++;
    });
    maxWin+=minWin;
    answer.push(wins[maxWin]);
    answer.push(wins[minWin]);
    return answer;
}