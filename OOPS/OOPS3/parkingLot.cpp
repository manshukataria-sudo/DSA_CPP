#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;
class Vehicle {
   private:
    string name;
    string vehNo;
    int seatNo;

   public:
    void setSeatNo(int seatNo) { this->seatNo = seatNo; }
    void setName(string name) { this->name = name; }
    void setVehNo(string vehNo) { this->vehNo = vehNo; }
    int getSeatNo() { return this->seatNo; }
};
class ParkingLot {
   private:
    vector<Vehicle> parked;
    vector<int> cap = {0, 0, 0, 0, 0};
    int occSeats = 0;
    int unOccSeats = 5;

   public:
    void getOccSeats() { cout << this->occSeats << " SEATS ARE OCCUPIED" << endl; }
    void getUnOccSeats() {
        if (this->unOccSeats == 0) {
            cout << "...ALL SEATS OCCUPIED..." << endl;
            return;
        }
        cout << this->unOccSeats << " SEATS ARE AVAILABLE" << endl;
    }
    void checkUnOcc() {
        if (this->unOccSeats == 0) {
            cout << "...ALL SEATS OCCUPIED..." << endl;
            return;
        }
        for (int i = 0; i < this->cap.size(); i++) {
            if (this->cap[i] == 0)
                cout << "...POSITION " << i + 1 << " IS AVAILABLE..." << endl;
        }
    }
    void checkOcc() {
        if (this->unOccSeats == 5) {
            cout << "...ALL SEATS ARE AVAILABLE..." << endl;
            return;
        }
        for (int i = 0; i < this->cap.size(); i++) {
            if (this->cap[i] == 1)
                cout << "...POSITION " << i + 1 << " IS OCCUPIED..." << endl;
        }
    }
    void parkVehicle() {
        if (occSeats == 5) {
            cout << "...SORRY !! PARKING LOT OCCUPIED..." << endl;
            return;
        }

        cin.ignore();  // numeric_limits<streamsize>::max(),'\n'

        string vehicle;
        cout << "Enter the vehicle type : " << endl;

        getline(cin, vehicle);

        if (vehicle == "car" || vehicle == "bike" || vehicle == "scooter")
            cout << "...PERMISSION GRANTED..." << endl;
        else {
            cout << "...PERMISSION DENIED..." << endl;
            return;
        }
        Vehicle* park = new Vehicle;
        park->setName(vehicle);

        string vehNo;
        cout << "Enter the " << vehicle << "'s LICENCE PLATE number : " << endl;
        getline(cin, vehNo);
        park->setVehNo(vehNo);
        this->checkUnOcc();
        int seatNo;
        cout << "Enter the seat number you want : ";
        cin >> (seatNo);
        park->setSeatNo(seatNo);
        this->parked.push_back(*park);
        this->occSeats++;
        this->unOccSeats--;
        this->cap[seatNo - 1] = 1;
        cout << "...NOW YOU CAN PARK YOUR VEHICLE..." << endl;
        cout << "...PRESS ENTER TO PRINT THE RECIPT..." << endl;
        return;
    }
    void unParkVehicle() {
        if (this->occSeats == 0) {
            cout << "...EMPTY PARKING LOT..." << endl;
            return;
        }
        int seatNo;
        cout << "Enter the seat number to unpark the vehicle : ";
        cin >> seatNo;
        this->occSeats--;
        this->unOccSeats++;
        this->cap[seatNo - 1] = 0;
        cout << "...NOW YOU CAN UNPARK YOUR VEHICLE..." << endl;
        for (int i = 0; i < this->parked.size(); i++) {
            if (this->parked[i].getSeatNo() == seatNo) {
                for (int j = i; j < this->parked.size() - 1; j++) {
                    parked[j] = parked[j + 1];
                }
                i = this->parked.size();
            }
        }
        return;
    }
};
int main() {
    ParkingLot kc;
    kc.checkOcc();
    kc.unParkVehicle();
    kc.checkUnOcc();
    kc.getOccSeats();
    kc.parkVehicle();
    kc.parkVehicle();
    kc.parkVehicle();
    kc.parkVehicle();
    kc.parkVehicle();
    kc.unParkVehicle();
    kc.unParkVehicle();
    kc.unParkVehicle();
    kc.unParkVehicle();
    kc.unParkVehicle();
    kc.unParkVehicle();
}