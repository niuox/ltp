#ifndef __LTP_SRL_RULE_BASED_H__
#define __LTP_SRL_RULE_BASED_H__

#include <vector>
#include <iostream>

namespace ltp {
namespace srl {
namespace rulebase {

static bool dll_validity_check(
    const std::vector<std::string> & words,
    const std::vector<std::string> & postags,
    const std::vector<std::string> & nes,
    const std::vector<std::pair<int,std::string> > & parser) {
  if(words.size()!=postags.size()||words.size()!=parser.size()||words.size()!=nes.size()) {
    return false;
  }

  int len = parser.size(); 

  for(int i =0;i<len;++i) {
    if(words[i].empty()) {
      return false;
    }
  }

  for(int i =0;i<len;++i) {
    if(postags[i].empty()) {
      return false;
    }
  }

  for(int i =0;i<len;++i) {
    if(nes[i].empty()) {
      return false;
    }
  }

  for(int i = 0;i<len; ++i) {
    int father = parser[i].first;
    if(father<-1||father>=len||parser[i].second.empty()) {
      return false;
    }
  }



  return true;
}

}//end rulebase
}//end srl
}//end ltp
#endif