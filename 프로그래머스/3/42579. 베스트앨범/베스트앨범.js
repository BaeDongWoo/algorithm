function solution(genres, plays) {
    var answer = [];
    let totalPlays =new Map();
    let setPlayList = new Map();
    for(let i=0;i<genres.length;i++){
        if(totalPlays.get(genres[i])===undefined) totalPlays.set(genres[i],plays[i]);
        else totalPlays.set(genres[i],totalPlays.get(genres[i])+plays[i]);
        
        if(setPlayList.get(genres[i])===undefined) setPlayList.set(genres[i],[[i,plays[i]]]);
        else setPlayList.set(genres[i],[...setPlayList.get(genres[i]),[i,plays[i]]]);
    }
    let totalPlaysToArr = [...totalPlays];
    totalPlaysToArr.sort((a,b)=>b[1]-a[1]);
    setPlayList.forEach((m)=>{
        m.sort((a,b)=>{
            if(a[1]===b[1]) return a[0]-b[0];
            else return b[1]-a[1];
        })
    })
    for(let i=0;i<totalPlaysToArr.length;i++){
        const playList = setPlayList.get(totalPlaysToArr[i][0]);
        const ans = playList.slice(0,2);
        console.log(ans);
        ans.map((e)=>{
            answer.push(e[0]);
        })
        // answer.push(playList[0][0]);
        // if(playList.length >1)answer.push(playList[1][0]);
    }
    return answer;
}
/*
sol
1. 장르별로 총 재생 횟수를 저장 후 저장 횟수별로 내림차순 정렬 ex) classic: 2000
2. 해당 장르별 고유 번호와 재생 횟수를 저장
3. 
*/