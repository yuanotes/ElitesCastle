#include <vector>
using namespace std;

// [d1, d2]: d1 means oil in the stop and d2 means oil need to next stop.
typedef pair<double, double> Stop;
typedef vector<Stop> Path;

// Get stop index from which the car can get through all the stop.
int get_stop(Path path){
    auto stop_count = path.size();

    if (stop_count < 1){
        // error path
        return -1;
    }

    for (int start_stop_index = 0; start_stop_index <= (stop_count - 1); start_stop_index++){

        int past_stop_count = 0;
        double car_has = 0;

        while(past_stop_count < stop_count){
            auto current_stop_index = (start_stop_index + past_stop_count) % stop_count;
            Stop current_stop = path[current_stop_index];
            car_has += current_stop.first;
            if (car_has >= current_stop.second){
                // oil is ok and get to next stop
                past_stop_count++;
            } else {
                // oil is not enough
                break;
            }
        }
        if (past_stop_count == stop_count){
            return start_stop_index;
        }
    }
    return -1;
}