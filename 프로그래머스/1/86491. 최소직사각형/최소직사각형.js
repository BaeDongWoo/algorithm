function solution(sizes) {
    var answer = 0;
    sizes.map((size)=>size.sort((a,b)=>b-a));
    let width=0;
    let heigth=0;
    for(let i = 0;i<sizes.length;i++){
        if(width<sizes[i][0])width=sizes[i][0];
        if(heigth<sizes[i][1])heigth=sizes[i][1]
    }
    answer = width*heigth;
    return answer;
}
// 가로 세로 중 더 긴걸 가로로 하는 새로운 배열 생성
// 최대 가로와 최소 가로  