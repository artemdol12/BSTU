#include <iostream>
#include <string>

typedef unsigned short Metr;       
typedef unsigned char RoomCount;   
typedef unsigned short Year;       
typedef unsigned char Floor;       
typedef bool HasFeature;           

struct Apartment {
    Metr area;                     
    RoomCount rooms;               
    Year yearBuilt;                
    Floor floor;                
    HasFeature hasKitchen;      
    HasFeature hasBathroom;     
    HasFeature hasToilet;       
    HasFeature hasBasement;     
    HasFeature hasBalcony;         
};
bool operator==(const Apartment& a1, const Apartment& a2) {
    return a1.yearBuilt == a2.yearBuilt;
}
Apartment operator+(const Apartment& a1, const Apartment& a2) {
    Apartment result;
    result.rooms = a1.rooms + a2.rooms; 
    return result;
}
int main() {
    setlocale(LC_ALL, "rus");

    Apartment apartment1 = { 80, 3, 2000, 5, true, true, true, false, true };
    Apartment apartment2 = { 120, 4, 2005, 7, true, true, true, true, false };

    if (apartment1 == apartment2) {
        std::cout << "Квартиры построены в одном году." << std::endl;
    }
    else {
        std::cout << "Квартиры построены в разных годах." << std::endl;
    }

    Apartment totalRooms = apartment1 + apartment2;
    std::cout << "Общее количество комнат в двух квартирах: " << static_cast<int>(totalRooms.rooms) << std::endl;

    return 0;
}