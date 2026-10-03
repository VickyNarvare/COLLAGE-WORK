// Graph banaya hai
// A se B jaane ka cost = 2
// A se C jaane ka cost = 5

let graph = {
  A: { B: 2, C: 5 },
  B: { A: 2, C: 1, D: 3 },
  C: { A: 5, B: 1 },
  D: { B: 3 },
};

// Shortest path find karne ka function
// start = kaha se start karna hai
// end = kaha tak jaana hai

function shortestPath(start, end) {
  // Sabhi nodes ki distance initially Infinity
  // Matlab abhi hume kisi node ki exact distance nahi pata

  let dist = {
    A: Infinity,
    B: Infinity,
    C: Infinity,
    D: Infinity,
  };

  // Ye track karega ki kaunsa node already check ho chuka hai

  let visited = {};

  // Starting node ki distance 0 hoti hai
  // Kyunki A se A jaane me distance 0 hai

  dist[start] = 0;

  // Jab tak destination nahi milta, loop chalega

  while (true) {
    // Abhi koi current node select nahi kiya

    let current = null;

    // Graph ke har node ko check karenge

    for (let node in dist) {
      // Jo node abhi visit nahi hua
      // aur jiski distance sabse kam hai,
      // use current node bana do

      if (!visited[node] && (current == null || dist[node] < dist[current])) {
        current = node;
      }
    }

    // Agar current node destination hai
    // to hume aur check karne ki zarurat nahi

    if (current == end) {
      break;
    }

    // Current node ko visited mark kar do

    visited[current] = true;

    // Current node ke saare neighbours check karo

    for (let next in graph[current]) {
      // Current node tak ki distance
      // + current se next node ki distance

      let newDist = dist[current] + graph[current][next];

      // Agar nayi distance purani distance se chhoti hai
      // to distance update kar do

      if (newDist < dist[next]) {
        dist[next] = newDist;
      }
    }
  }

  // Destination ki shortest distance return karo

  return dist[end];
}

// Function ko call kiya
// A se D tak shortest distance find karni hai

console.log(shortestPath("A", "D"));
