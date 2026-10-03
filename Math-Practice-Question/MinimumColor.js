// Graph
let graph = {
  // A ke neighbours: B and C
  A: ["B", "C"],

  // B ke neighbours: A and C
  B: ["A", "C"],

  // C ke neighbours: A and B
  C: ["A", "B"],
};

// Map coloring function
function mapColoring(graph) {
  // Har node ka color yahan store hoga
  let color = {};

  // Har node ko one by one check karo
  for (let node in graph) {
    // Neighbours ke already used colors store honge
    let usedColors = [];

    // Current node ke neighbours check karo
    for (let neighbour of graph[node]) {
      // Agar neighbour ko color mil chuka hai
      if (color[neighbour] !== undefined) {
        // Neighbour ka color save karo
        usedColors.push(color[neighbour]);
      }
    }

    // Sabse chhota color 0 se start karo
    let c = 0;

    // Agar color already used hai
    // to next color try karo
    while (usedColors.includes(c)) {
      c++;
    }

    // Current node ko available color de do
    color[node] = c;
  }

  // Final colors return karo
  return color;
}

// Function call
console.log(mapColoring(graph));
