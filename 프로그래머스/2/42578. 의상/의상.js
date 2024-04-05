function solution(clothes) {
  let types = {};
  let result = 1;

  clothes.forEach((v) => (types[v[1]] = (types[v[1]] || 0) + 1));
  for (const key in types) {
    result *= types[key] + 1;
  }
  return result - 1;
}