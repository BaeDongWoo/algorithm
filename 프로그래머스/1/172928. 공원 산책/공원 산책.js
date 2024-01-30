function solution(park, routes) {
  // 직사각형 공원이 가로 세로 길이
  const maxRow = park.length - 1;
  const maxCol = park[0].length - 1;

  // 시작 지점의 좌표를 구한다.
  // findIndex(), includes() 메서드를 이용해 몇 번째 행에 있는지를 구한다.
  // 구한 행에서 indexOf() 메서드를 이용해 몇 번째 열에 있는지 구한다.
  let row = park.findIndex((s) => s.includes("S"));
  let col = park[row].indexOf("S");

  // routes를 forEach() 메서드를 이용해 요소를 하나씩 확인한다.
  routes.forEach((position) => {
    // 요소를 빈칸 기준으로 나눠준다. (구조분해할당을 이용)
    // d = "E" / n = "2"
    const [d, n] = position.split(" ");

    // 임시 좌표를 만들어주고 flag도 하나 만들어준다.
    let tempRow = row;
    let tempCol = col;
    let flag = true;

    // 구한 이동거리 수 만큼 for문을 돌려준다.
    for (let i = 0; i < Number(n); i++) {

      // 동서 쪽 일 경우 행을 더하거나 빼주고
      // 남북 쪽 일 경우 열을 더하거나 빼준다.
      if (d === "E") tempCol++;
      else if (d === "W") tempCol--;
      else if (d === "S") tempRow++;
      else if (d === "N") tempRow--;

      // 그 후 행과 열이 공원을 벗어나는지
      // 행과 열의 좌표에 장애물이 없는지를 확인한다.
      if (
        tempRow > maxRow ||
        tempRow < 0 ||
        tempCol > maxCol ||
        tempCol < 0 ||
        park[tempRow][tempCol] === "X"
      ) {
        // 장애물이 있거나 공원을 벗어났다면
        // flag에 false를 넣어주고 break를 통해 for문을 종료시킨다.
        flag = false;
        break;
      }
    }

    // for문을 무사히 통과했다면 이동을 한 것이기 때문에
    // 임시 좌표를 실제 좌표에 대입해준다.
    if (flag) {
      col = tempCol;
      row = tempRow;
    }
  });

  // 다 확인 후 마지막 좌표를 반환한다.
  return [row, col];
}