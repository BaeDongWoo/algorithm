function solution(k, tangerine) {
    var answer = 0;
    
    let tangerine_cnt = new Array(10000001).fill(0);
    
    for(let i = 0;i<tangerine.length ;i++){
        tangerine_cnt[tangerine[i]]++;
    }
    tangerine_cnt.sort((a,b) => b-a);
    
    let cnt = 0;
    
    for(let i =0;i<tangerine_cnt.length;i++){
        cnt+=tangerine_cnt[i];
        if(cnt >= k) return i+1;
    }
    return answer;
}
// 종류별로 묶고 많은 갯수부터 담으면 됨 
//