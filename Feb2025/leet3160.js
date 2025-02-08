// 3160. Find the Number of Distinct Colors Among the Balls
/**
 * @param {number} limit
 * @param {number[][]} queries
 * @return {number[]}
 */
var queryResults = function (limit, queries) {
  let ans = [];
  let ballToColor = new Map();
  let colorCount = new Map();

  for (let [ball, color] of queries) {
    if (ballToColor.has(ball)) {
      let prevColor = ballToColor.get(ball);
      colorCount.set(prevColor, (colorCount.get(prevColor) || 0) - 1);
      if (colorCount.get(prevColor) === 0) {
        colorCount.delete(prevColor);
      }
    }
    ballToColor.set(ball, color);
    colorCount.set(color, (colorCount.get(color) || 0) + 1);
    ans.push(colorCount.size);
  }

  return ans;
};
