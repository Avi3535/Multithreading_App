/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<iostream>
#include<thread>
#include<map>
#include<string>
#include <random>
#include<chrono>
using namespace std;


 
std::random_device rd;
std::mt19937 gen(rd());
int random(int low, int high)
{
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

void RefreshForecastMap(map<string, int> forecastMap){
    while(true){
        for(auto& item: forecastMap){
            item.second = random(item.second-3, item.second+3);;
            std::cout << item.first << " - " << item.second << std::endl;
        }
        this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main(){
    map<string, int> forecastMap = {
        {"Mumbai", 26},
        {"Vancouver", 16},
        {"New York", 16},
    };
    thread bgWorker(RefreshForecastMap, forecastMap);

system("pause>nul");
}
