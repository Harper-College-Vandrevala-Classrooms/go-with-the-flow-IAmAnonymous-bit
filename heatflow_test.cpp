using namespace std;

#include <iostream>
#include <vector>
#include "heatflow.hpp"

int main()
{
    float k = 0.1;
    float initial_temperature = 10.0;
    int num_of_times = 5;
    vector<float> sources_and_sinks(num_of_times);
    sources_and_sinks[0] = 100;
    Heatflow heatflow(10.0, 5, 0.1, sources_and_sinks);

    heatflow.pretty_print();

    heatflow.tick();

    heatflow.pretty_print();

    heatflow.tick();

    heatflow.pretty_print();

    heatflow.tick();

    heatflow.pretty_print();

    heatflow.tick();

    heatflow.pretty_print();

    return 0;
}