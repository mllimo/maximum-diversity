#ifndef GRASP_MD_H
#define GRASP_MD_H

#include <greedy_md.h>
#include <local_search_md.h>
#include <stop_condition_md.h>

#include <iostream>
#include <random>

class GraspMd : public GreedyMd {
 public:
  /**
   * @brief Constructor de la clase Grasp. Inicializa las variables que serán necesitas dentro de la
   * resolución del problema
   * @param k Tamaño de la lista aleatorio de candidatos
   * @param stop Criterio de parada
   * @param local Si se desea se puede añadir una busqueda local después de la construcción
   */
  GraspMd(size_t k, StopConditionMd* stop, LocalSeachMd* local = NULL);
  virtual ~GraspMd();

  virtual void operator()(std::set<std::vector<float>>& solution,
                          const std::set<std::vector<float>>& data, const size_t m);

 protected:
  size_t k;
  StopConditionMd* stop_condition;
  LocalSeachMd* local_search;

  void Construct(std::set<std::vector<float>>& solution, const std::set<std::vector<float>>& data,
                 const size_t m);

  std::vector<std::vector<float>> MakeRcl(std::set<std::vector<float>> actual_candidates,
                                          const std::vector<float>& point);

  std::vector<float> SelectionRandom(const std::vector<std::vector<float>>& random_list);
};

#endif