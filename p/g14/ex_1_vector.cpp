//
// Algoritmos e Estruturas de Dados --- 2023/2024
//
// STL Containers - Performance
//

#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

int main(void) {
  const size_t MIN = 1000;
  const size_t MAX = 100000;

  for (size_t size = MIN; size <= MAX; size *= 10) {
    cout << endl;

    // 1st vector container --- appending at the end

    vector<double> v1;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for (size_t i = 0; i < size; i++) {
      v1.push_back(i);
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2 - t1).count();

    cout << "Filling a vector of size: " << size << " by appending at the END" << endl;
    cout << "Execution time: " << duration << " microseconds" << endl;

    t1 = high_resolution_clock::now();

    double sum = 0.0;
    for (size_t i = 0; i < size; i++) {
      sum += v1[i];
    }

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();

    cout << "Going through the vector and computing its average value: " << sum / v1.size() << endl;
    cout << "Execution time: " << duration << " microseconds" << endl;

    t1 = high_resolution_clock::now();

    for (size_t i = 0; i < size; i++) {
      v1.pop_back();
    }

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();

    cout << "Erasing the elements one by one and moving backwards: " << endl;
    cout << "Execution time: " << duration << " microseconds" << endl;
    cout << endl;

    // 2nd vector container --- inserting at the beginning

    vector<double> v2;

    t1 = high_resolution_clock::now();

    for (size_t i = 0; i < size; i++) {
      v2.insert(v2.begin(), i);
    }

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();

    cout << "Filling a vector of size: " << size
         << " by inserting at the BEGINNING" << endl;
    cout << "Execution time: " << duration << " microseconds\n";

    t1 = high_resolution_clock::now();

    sum = 0.0;
    for (int i = size - 1; i >= 0; i--) {
      sum += v2[i];
    }

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();

    cout << "Going backwards through the vector and computing its average "
            "value: "
         << sum / v2.size() << endl;
    cout << "Execution time: " << duration << " microseconds\n";

    t1 = high_resolution_clock::now();

    for (size_t i = 0; i < size; i++) {
      v2.erase(v2.begin());
    }

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();

    cout << "Erasing the FIRST ELEMENT until the vector is empty: " << endl;
    cout << "Execution time: " << duration << " microseconds\n";

    cout << endl;
  }

  return 0;
}