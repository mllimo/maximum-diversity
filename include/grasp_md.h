#ifndef GRASP_MD_H
#define GRASP_MD_H

#include <greedy_md.h>
#include <stop_condition_md.h>
#include <random>

#include <iostream>

class GraspMd : public GreedyMd {
 public:
  GraspMd(size_t k);  // Criterio de parada
  virtual ~GraspMd();

  virtual void operator()(std::set<std::vector<float>>& solution,
                          const std::set<std::vector<float>>& data, const size_t m);

 protected:
  size_t k;
  StopConditionMd* stop_condition;

  void Construct(std::set<std::vector<float>>& solution, const std::set<std::vector<float>>& data,
                 const size_t m);
  std::vector<std::vector<float>> MakeRcl(std::set<std::vector<float>> actual_candidates,
                                          const std::vector<float>& point);
  std::vector<float> SelectionRandom(const std::vector<std::vector<float>>& random_list);
};

#endif