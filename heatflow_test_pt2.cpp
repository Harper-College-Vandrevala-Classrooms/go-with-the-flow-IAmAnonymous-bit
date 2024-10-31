using namespace std;

#include <iostream>
#include <vector>
#include "heatflow.hpp"

int main()
{
    float k = 0.1;
    float initial_temperature = 10.0;
    int num_of_times = 5;
    vector<float> sources_and_sinks1(num_of_times);
    sources_and_sinks1[2] = 100;
    Heatflow heatflow1(10.0, 5, 0.1, sources_and_sinks1);

    heatflow1.pretty_print();

    heatflow1.tick();

    heatflow1.pretty_print();

    heatflow1.tick();

    heatflow1.pretty_print();

    vector<float> sources_and_sinks2(num_of_times);
    sources_and_sinks2[0] = 100;
    sources_and_sinks2[sources_and_sinks2.size()-1] = 100;
    Heatflow heatflow2(10.0, 5, 0.1, sources_and_sinks2);

    heatflow2.pretty_print();

    heatflow2.tick();

    heatflow2.pretty_print();

    heatflow2.tick();

    heatflow2.pretty_print();

    return 0;
}