using namespace std;

#include <iostream>
#include <vector>
#include <sstream>
#include "heatflow.hpp"

Heatflow::Heatflow(float initial_temperature, int number_of_sections, float k, vector<float> sources_and_sinks)
{
    this->k = k;
    this->initial_temperature = initial_temperature;
    for (int i = 0; i < number_of_sections; i++)
    {
        if(sources_and_sinks[i] != 0)
        {
            this->rod.push_back(sources_and_sinks[i]);
            this->source_and_sinks.push_back(true);
        } else {
            this->rod.push_back(initial_temperature);
            this->source_and_sinks.push_back(false);
        }
    }
}

void Heatflow::tick()
{
    float prev_temp;

    prev_temp = this->rod[0];
    if (!source_and_sinks[0])
    {
        this->rod[0] = this->rod[0] + (this->k * (this->rod[1] - (2 * this->rod[0]) + initial_temperature));
    }

    
    for (int i = 1; i < this->rod.size()-1; i++)
    {
        float cur_prev_temp = prev_temp;
        prev_temp = this->rod[i];
        if (!source_and_sinks[i])
        {
            this->rod[i] = this->rod[i] + (this->k * (this->rod[i+1] - (2 * this->rod[i]) + cur_prev_temp));
        }
    }

    bool end_is_s;
    
    if(!source_and_sinks[source_and_sinks.size()-1])
    {
        this->rod[this->rod.size()-1] = this->rod[this->rod.size()-1] + (this->k * (initial_temperature - (2 * this->rod[this->rod.size()-1]) + prev_temp));
    }
}


void Heatflow::pretty_print()
{
    string center = "|";
    string side;

    for (int i = 0; i < this->rod.size(); i++)
    {
        stringstream ss;
        ss << rod[i];
        center += " " + ss.str() + " |";
    }

    for (int i = 0; i < center.length(); i++)
    {
        if (center[i] == '|')
        {
            side += "+";
        } else {
            side += "-";
        }
    }

    cout << side << endl << center << endl << side << endl;

}