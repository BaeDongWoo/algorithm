function solution(wallpaper) {
    var answer = [];
    let minX=987654321;
    let minY=987654321;
    let maxX=0;
    let maxY=0;
    for(let i =0;i<wallpaper.length;i++){
        for(let j=0;j<wallpaper[i].length;j++){
            if(wallpaper[i][j]==='#'){
                if(minX>i)minX=i;
                if(minY>j)minY=j;
                if(maxX<=i)maxX=i+1;
                if(maxY<=j)maxY=j+1;
            }
        }
    }
    answer=[minX,minY,maxX,maxY];
    return answer;
}
// 시작점은 0,0 끝점은 i,j
// 최소 x,y 부터 최대 x,y까지 범위 
// 