#include <iostream>

using namespace std;

class drone{
    public:
        int home[3];

        void checkBattery(){
            cout << battery << "% battery left";
        }

        void getPosition(){
            cout << cur_loc[0] << cur_loc[1] << cur_loc[2];
        }

    private:
        int battery;
        int cur_loc[3];

};