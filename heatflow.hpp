#pragma once

using namespace std;

#include <vector>

class Heatflow
{
    private:
        vector<float> rod;
        float k;
        float initial_temperature;
        vector<int> source_and_sinks;

    public:
        Heatflow(float initial_temperature, int number_of_sections, float k, vector<float> sources_and_sinks);
        void tick();
        void pretty_print();
};