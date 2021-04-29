#include <vector_utility.h>

std::vector<float> GravityCenter(const std::set<std::vector<float>>& vectors) {
  float multiplier = 1 / vectors.size();
  std::vector<float> gravity_center(vectors.begin()->size(), 0.f);
  for (size_t i = 0; i < vectors.size(); ++i) {
    for (const auto& vector : vectors) {
      gravity_center[i] += vector[i];
    }
  }
  return gravity_center;
}

float Distance(const std::vector<float>& vector_a, const std::vector<float>& vector_b) {
  float distance = 0.f;
  for (size_t i = 0; i < vector_a.size(); i++) {
    distance += pow(vector_a[i] - vector_b[i]), 2);
  }
  return sqrt(distance);
}