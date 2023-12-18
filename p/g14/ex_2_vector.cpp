//
// Algoritmos e Estruturas de Dados --- 2023/2024
//
// Algorithms - Performance
//

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

int main(void) {
  const size_t MIN = 1000;
  const size_t MAX = 1000000;

  for (size_t size = MIN; size <= MAX; size *= 10) {
    cout << "\n";

    vector<int> random_vector;

    //~ Filling the vector

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for (size_t i = 0; i < size; i++) {
      random_vector.push_back(rand() % (10 * size));
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2 - t1).count();

    cout << "Filling a vector of size " << size << " with random values in "
         << duration << " microseconds\n";

    //~ Min and Max elements

    t1 = high_resolution_clock::now();

    auto [it_min, it_max] =
        minmax_element(random_vector.begin(), random_vector.end());

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();

    cout << "Min value: " << *it_min << " Max value: " << *it_max << "\n";
    cout << "Execution time: " << duration << " microseconds\n";

    //~ All even ?

    t1 = high_resolution_clock::now();

    if (all_of(random_vector.begin(), random_vector.end(),
               [](int i) { return i % 2 == 0; })) {
      cout << "All numbers are even\n";
    } else {
      cout << "NOT all numbers are even\n";
    }

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "Execution time: " << duration << " microseconds\n";

    //~ Count even

    t1 = high_resolution_clock::now();

    size_t count_even = count_if(random_vector.begin(), random_vector.end(),
                                 [](int i) { return i % 2 == 0; });

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "Even numbers: " << count_even << "\n";
    cout << "Execution time: " << duration << " microseconds\n";

    //~ Copying

    t1 = high_resolution_clock::now();

    vector<int> copy_vector = random_vector;

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "Copying the random_vector\n";
    cout << "Execution time: " << duration << " microseconds\n";

    //~ Searching (sequential)

    cout << "Searching for " << size / 10 << " random values in the vector... ";

    size_t found = 0;

    t1 = high_resolution_clock::now();

    for (size_t i = 0; i < size / 10; i++) {
      int svalue = rand() % (10 * size);
      auto it = find(copy_vector.begin(), copy_vector.end(), svalue);

      if (it != copy_vector.end()) {
        found++;
      }
    }

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "Found " << found << " values in " << duration << " microseconds\n";

    //~ Sorting

    t1 = high_resolution_clock::now();

    sort(random_vector.begin(), random_vector.end());

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "Sorting done in " << duration << " microseconds\n";

    //~ Is sorted

    t1 = high_resolution_clock::now();

    if (is_sorted(random_vector.begin(), random_vector.end())) {
      cout << "Vector is sorted!!\n";
    } else {
      cout << "*** Vector is NOT sorted!! ***\n";
    };

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "Execution time: " << duration << " microseconds\n";

    //~ Binary search

    cout << "BINARY Searching for " << size / 10
         << " random values in the vector... ";

    found = 0;

    t1 = high_resolution_clock::now();

    for (size_t i = 0; i < size / 10; i++) {
      int svalue = rand() % (10 * size);

      bool res =
          binary_search(random_vector.begin(), random_vector.end(), svalue);

      if (res) {
        found++;
      }
    }

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "Found " << found << " values in " << duration << " microseconds\n";

    //~ Removing duplicates

    t1 = high_resolution_clock::now();

    auto last = unique(random_vector.begin(), random_vector.end());
    random_vector.erase(last, random_vector.end());

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "Removing duplicates in " << duration << " microseconds\n";

    //~ Erasing the vector

    t1 = high_resolution_clock::now();

    copy_vector.erase(copy_vector.begin(), copy_vector.end());

    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    cout << "Erasing the copied vector in " << duration << " microseconds\n";
  }

  return 0;
}
