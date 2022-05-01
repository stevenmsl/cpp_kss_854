#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
using namespace sol854;
using namespace std;

/*takeaways
  - use BFS
  - the key is to find the legit neighbors
  - A and B anagrams so by rearranging the letters in A
    will give us B
    - A = "aeebccghhk" B="beegcckhha"
    - A's neighbors:
      "beeaccghhk" (swap a with b)
      "aeegccbhhk" (swap b with g)
      "keebccghha" (swap a with k)
    - these neighbors are one step closer to B
    - we don't touch those letters that are
      in place already like ee, cc, hh
*/

int Solution::minSteps(string A, string B)
{
  auto q = queue<string>{{A}};
  auto visited = unordered_set<string>{{A}};
  auto steps = 0;
  const int n = A.size();

  while (!q.empty())
  {
    int size = q.size();
    while (size > 0)
    {
      auto v = q.front();
      q.pop();

      if (v == B)
        return steps;

      /* find the neighbors */
      auto i = 0;
      /* find where it differs */
      while (v[i] == B[i] && i < n)
        i++;
      /*
        - basically we are doing this here
        - v=adeeg B=ageed
        - for v we skip the "ee", as they are
          already in place and don't need
          be swapped, to find 'g' in v
          to swap with 'd' in v to
          get ageed
        - in a nutshell every swap will
          put one more char in place so
          we can move closer toward B
      */
      for (auto j = i + 1; j < n; j++)
      {
        /* we are not swapping these as
           they are either in place and
           it won't help swapping them
        */
        if (v[j] == B[j] || v[j] != B[i])
          continue;
        /* new neighbor - on step closer to B */
        swap(v[i], v[j]);
        if (!visited.count(v))
          visited.insert(v),
              q.push(v);
        /* as usual you need to retore the state to
           find the next neighbor of v
        */
        swap(v[i], v[j]);
      }
      size--;
    }
    steps++;
  }

  return steps;
}
