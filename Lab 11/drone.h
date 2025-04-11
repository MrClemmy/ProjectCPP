#include <iostream>

using namespace std;

class Drone{
    public:
        int home[3];

        void checkBattery(){
            cout << battery << "% battery left" << endl;
        }

        void getPosition(){
            cout << "(" << cur_loc[0] << ", " << cur_loc[1] << ", " << cur_loc[2] << ")" << endl;
        }

        void landDrone(){
            while(cur_loc[2] > 0){
                cur_loc[2] -= 1;
            }
            cout << "Drone is on the ground at ";
            getPosition();
        }

        void move(string direction, int distance){
            if (distance <= 0){
                cout << "enter a positive distance please!" << endl;
            }
            if(battery <= 2){
                cout << "Your drone dies and crashes :(" << endl;
                return;
            }
            if (direction == "forward"){
                cur_loc[1] += distance;
                battery -= 2;
            }
            else if (direction == "backward"){
                cur_loc[1] -= distance;
                battery -= 2;
            }
            else if (direction == "right"){
                cur_loc[0] += distance;
                battery -= 2;
            }
            else if (direction == "left"){
                cur_loc[0] -= distance;
                battery -= 2;
            }
            else if (direction == "up"){
                cur_loc[2] += distance;
                battery -= 2;
            }
            else if (direction == "down"){
                if(cur_loc[2] > distance){
                    cur_loc[2] -= distance;
                    battery -= 2;
                } else {
                    cout << "error: drone is too low for that distance!" << endl;
                    return;
                }
            }
            else {
                cout << "error: invalid direction" << endl;
            }
        }

        Drone(){
            battery = 100;
            for (int i = 0; i < 3; ++i) {
                cur_loc[i] = 0;
                home[i] = 0;
            }
        }

    private:
        int battery;
        int cur_loc[3];

};