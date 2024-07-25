function solution(clothes) {
    let result = 1;
    let clothesTable = new Map();
    clothes.map((c)=>{
        if(clothesTable.get(c[1])===undefined) clothesTable.set(c[1],1);
        else clothesTable.set(c[1],clothesTable.get(c[1])+1);
    });
    clothesTable.forEach((c)=>{
        result*=c+1;
    })
    console.log(result);
    return result-1;
}
// 경우의 수는 모든 옷 종류 + 옷 조합
// 옷 조합 = 모든 옷 곱하기