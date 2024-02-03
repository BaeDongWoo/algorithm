function solution(bandage, health, attacks) {
    const maxCasting = bandage[0];
    const castingHeal = bandage[1];
    const addRecovery=bandage[2];
    const maxHP=health;
    let pointer = 0;
    let casting = 0;
    let turn = 0;
    while(pointer<attacks.length){
        turn++;
        if(attacks[pointer][0]===turn){//공격 시간일 때 체력 감소
            casting=0;
            health-=attacks[pointer][1];
            if(health<=0) {//감소한 체력이 0이하이면 -1리턴
                return -1;
            }
            pointer++;
        }
        else{//공격 시간이 아니라면 체력회복
            casting++;
            health+=castingHeal;
            if(casting===maxCasting){
                casting=0;
                health+=addRecovery;
            }
            if(health>maxHP)health=maxHP;//최대 체력까지만 회복
        }
    }
    return health;
}
// 공격을 받지않으면 연속 성공일수가 ++ 
// 최대 연속 성공은 == 시전시간
// 최대 회복량= 연속성공*초당회복량 + 추가회복량
// 해당 턴에 공격을 당했는지 안당했는지 확인 