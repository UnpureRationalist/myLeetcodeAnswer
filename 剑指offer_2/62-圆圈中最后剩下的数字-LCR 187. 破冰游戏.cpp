#include "header.h"

class Solution {
 public:
  int iceBreakingGame(int num, int target) {
    int last = 0;
    for (int i = 2; i <= num; ++i) {
      last = (last + target) % i;
    }
    return last;
  }
};
